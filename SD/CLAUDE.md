# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository overview

This is a coursework repo for a "Sistemas Distribuídos" (Distributed Systems) college course. It is not a single application — it's a collection of independent, small Java network programming exercises, one (or a client/server pair) per Maven module. Each module is self-contained: its own `pom.xml`, its own `groupId`/`artifactId`, no shared parent POM, no inter-module dependencies.

Modules, grouped by assignment folder:

- **Aula1/** — TCP sockets basics
  - `Projeto` (`org.example`): TCP server (`ServidorTCP`) that accepts a client on port 3322, exchanges one message each way via `ObjectInputStream`/`ObjectOutputStream`, and shows results in Swing dialogs (`JOptionPane`).
  - `Sockets01_Client` (`org.example`): matching TCP client (`ClienteTCP`), hardcoded to connect to a specific IP (`200.128.142.203:3322`).
- **Aula2/** — UDP unicast and multicast
  - `demo` (`com.udp`): UDP receiver exercise, currently a stub (`Sockets02_Receiver_UDP` is empty).
  - `sender` (`com.udpsender`): UDP unicast sender to a hardcoded IP:port.
  - `sendermulticast` / `recievermulticast`: multicast sender/receiver pair over group `239.0.0.10:6668`. The receiver joins the group on a hardcoded network interface name (`wlp0s20f3` — must match the machine's actual Wi-Fi interface to run).
- **Urna/** — a toy distributed voting system combining both patterns from Aula1/Aula2
  - `urna` (`com.urna.Urna`): TCP server on port 3322 that receives votes for 3 candidates one at a time, then multicasts the winner to `239.0.0.10:6668` once 3 votes are in.
  - `eleitor` (`com.eleitor.Eleitor`): TCP client that casts one vote, then joins the multicast group to receive the announced winner.
- **chatmidlewareservice/** — an in-progress Swing desktop app (SystemTray-based chat middleware control panel). Most classes (`Run`, `MenuServidor`, `FrmPainelControle`) are early-stage/stub. Includes a bespoke `GUIBuilder/` tool (`WindowBuilder.java` + helper classes) used to generate Swing UI from `.swingbuilder.json` (style defaults) and `.swingbuilder-layout.json` (a serialized component layout for `FrmPainelControle`) — treat these two JSON files as the source of truth for that screen's layout rather than hand-editing generated Swing code.

## Build and run

Every module is built with plain Maven, Java 17, no build plugins configured (no shade/assembly plugin) and no test dependencies — `src/test/java` exists in each module but is empty.

From inside a given module directory (e.g. `Aula1/Projeto`, `Urna/urna`):

```bash
mvn compile                 # compile
mvn package                 # build (no fat jar — classpath is just target/classes)
mvn exec:java -Dexec.mainClass="<fully.qualified.Main>"   # run, if exec-maven-plugin is available; otherwise:
java -cp target/classes <fully.qualified.Main>
```

There is no test runner configured anywhere in this repo (no JUnit/TestNG dependency, no test classes) and no root/aggregator POM — always `cd` into the specific module before running Maven commands.

Because these are Swing (`JOptionPane`) apps talking over raw sockets, running one module in isolation (e.g. just `Urna/urna`) will block waiting for a dialog and/or a socket connection — client/server or sender/receiver pairs need to be started together, and multicast programs need a valid `NetworkInterface` name for the current machine.

## Working in this repo

- Treat each module as isolated: a change in one Aula/Urna module has no effect on any other module. Don't introduce cross-module dependencies or a shared parent POM unless explicitly asked.
- Hardcoded IPs, ports, and network interface names (e.g. `200.128.142.203`, `wlp0s20f3`) are exercise artifacts tied to a specific classroom/lab network — don't "fix" them into config unless asked; when changing them, keep them as plain hardcoded constants consistent with the existing style.
- Code and UI strings are in Brazilian Portuguese (`Digite a mensagem...`, `Servidor TCP iniciado...`); match that language for new user-facing strings and comments in these modules.
- This is coursework code, not production code: keep changes minimal and in the same style as the surrounding exercise (plain try/catch with `JOptionPane` error dialogs, no logging framework, no dependency injection) rather than introducing new patterns or libraries.
