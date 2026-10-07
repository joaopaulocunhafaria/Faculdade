# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

`SD-v4` is a Swing chat system ("inspirado no WhatsApp") for the Sistemas Distribuídos course, split into two independent NetBeans/Maven projects with no shared parent POM:

- **Chat_Middleware_Service** — the server. Runs as a SystemTray icon with a control panel (`FrmPainelDeControle`) that toggles four services: Desktop, Web, Terceiros (other languages) and Publicidade (multicast ads). Only the **Desktop** service is implemented; the other three toggles just change the button text (`//...` placeholders).
- **Chat_Cliente_Desktop** — the Swing client: `FrmLogin` (nickname, color, avatar) → `FrmChat` (conversation view + send box).

The parent `../CLAUDE.md` covers the rest of the course repo and the general conventions (Portuguese strings, keep coursework style, don't move hardcoded IPs/ports into config).

## Build and run

Both projects target **Java 21** (`maven.compiler.release=21`) — the code uses virtual threads (`Thread.ofVirtual()`), so Java 17 won't compile it. No dependencies, no tests.

```bash
cd Chat_Middleware_Service   # or Chat_Cliente_Desktop
mvn compile
java -Djdk.gtk.version=3 -cp target/classes pacote.Run        # server (tray icon)
java -Djdk.gtk.version=3 -cp target/classes pacote.FrmLogin   # client
```

All classes live in package `pacote`. The `exec.mainClass` in both `pom.xml` files (`com.mycompany...`) is stale NetBeans scaffolding and points at classes that don't exist, so plain `mvn exec:java` without `-Dexec.mainClass=pacote.Run` / `pacote.FrmLogin` will fail. `Chat_Middleware_Service.java` / `Chat_Cliente_Desktop.java` are empty "Hello World" mains — not the real entry points. `nbactions.xml` holds the NetBeans run config (adds `-Djdk.gtk.version=3`).

## Desktop chat protocol

Message flow spans both projects; each `Util.java` holds the shared constants:

1. **Client → server (port 6662)**: `FrmChat.gerarEenviarMensagem()` builds an HTML fragment (avatar `<img>`, colored nickname, mode Fala/Grita/Xinga, text-emoticons replaced with HTML entities), opens a new `Socket` per message and sends it with `ObjectOutputStream.writeUTF`.
2. **Server storage**: `DesktopRecepcaoThread` creates a new `ServerSocket(6662)` for each message, accepts one connection, then appends the HTML line to a flat file `Util.PathRepDesktop` (`~/Dados/RelatorioDesktop.txt` — the `~/Dados` directory must already exist).
3. **Server → client (port 6661)**: `DesktopEnvioThread` loops: reads the *entire* file, opens `ServerSocket(6661)`, accepts one client, `writeUTF`s the whole history, closes.
4. **Client polling**: a virtual thread in the `FrmChat` constructor connects to 6661 about once per second (2 s connect timeout) and, only when the history changed, clears `EdtConversa` and re-inserts it via `HTMLEditorKit.insertHTML` (redrawing every second would restart the GIF animations).

Emojis/GIFs: `BtnEmoji` opens `PopEmojis` (a `JPopupMenu` with a `JTabbedPane` of `GridLayout` panels, built by hand in `montarPopupEmojis()`). Clicking an item inserts a text token `[emoji:Nome]` / `[gif:Nome]` into `TxtMensagem`. The token is sent and stored as plain text, and each receiving client turns it into an `<img>` pointing at its own classpath resource in `renderizarTokens()` (case-insensitive, because Grita/Xinga uppercase the text). The images live in `Chat_Cliente_Desktop/src/main/resources/images/{emojis,gifs}/`, and the names must also be listed in `Util.emojis` / `Util.gifs`.

Maintenance mode: any `IOException` while connecting to the server (polling or sending) calls `entrarModoManutencao()`, which shows "Servidor em manutenção" in `EdtConversa` and disables input. The next successful poll restores the chat. On the server, "Desativar" stops both `DesktopRecepcaoThread` and `DesktopEnvioThread` (`fecharServidor()`), so clients notice it.

So there is no persistent connection: the file is the single source of truth, and clients re-download the full history on each poll. Things to keep in mind when changing this:
- The server IP is hardcoded as a literal (`"200.128.142.91"`) in two places in `FrmChat`, and the send port `6662` is a literal rather than a `Util` constant on the client side.
- `writeUTF` caps payloads at 64 KB, so the history broadcast breaks once the file grows past that.
- Images go in `src/main/resources`. Files under `src/main/java` (such as the avatar icons) are not copied to `target/classes` by Maven.
- `Chat_Middleware_Service/C:\Dados\RepositorioDesktop.txt` is a stray file left behind when a Windows-style path was used on Linux. It isn't read by the code.

## NetBeans GUI forms

`FrmPainelDeControle`, `FrmChat` and `FrmLogin` were made in the NetBeans GUI Builder: each has a `.form` XML next to it, and the code between `//GEN-BEGIN:` / `//GEN-END:` markers (`initComponents()`, the variable declarations) is regenerated from it. Layout or component changes belong in the `.form` file and the generated block together, or NetBeans will overwrite them. Handwritten logic goes inside the `//GEN-FIRST:event_...` handler bodies or outside the guarded sections.

Image paths are environment-specific:
- `FrmLogin` uses absolute paths under `/home/joao/Projetos/Sistemas-Distribuidos/SD-v4/...` for both the avatar icons and `Util.avatar`. This checkout lives elsewhere, so those icons won't load here. The client also embeds the avatar path in the message HTML as `file:...`, so every client machine needs that same path. The avatar mapping is also inconsistent: radio 2 shows the Flash icon but sets the Batman path, and radio 3 does the reverse.
- `MenuServidor` loads the tray icon as `"images/icone.jpeg"` relative to the working directory, but the file is at `src/main/java/pacote/images/icone.jpeg`.
