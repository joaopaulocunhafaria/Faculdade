# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

Coursework for **Computação Gráfica** (Computer Graphics) at CEFET-MG, inside the larger `Faculdade` monorepo (`../` holds BD, IA, SO, LFA, etc., each self-contained). There is no build system, no package, no test suite — each `Aula*/` directory is a set of standalone teaching scripts demonstrating one graphics concept, written in class.

Code and comments are in **Portuguese** (`largura`, `altura`, `tela`, `cordenadas`, `raio`). Keep new code in Portuguese to match.

## Running scripts

A virtualenv lives at `CG/venv` (Python 3.11 — matplotlib, numpy, Pillow):

```bash
./venv/bin/python Aula5/aula4_algoritmo_de_bresenham.py
# or: source venv/bin/activate
```

Three things that bite:

- **Scripts write output files to the current working directory**, not next to the script (`arq.py` → `circulo_rasterizado.png`, `vetorizada.py` → `circulo_vetorizado.svg`, `converter_rgb_cmyk.py` → `*.jpg`). The committed artifacts sit inside their `Aula*/` folders, so `cd` into the directory before running to reproduce them.
- The venv was created under `Aula2Polignos/` and later moved, so every hardcoded path inside it (`bin/activate*`, the console-script shebangs, `pyvenv.cfg`) pointed at a directory that no longer exists — `source venv/bin/activate` silently left the system `python3` on the PATH. Those paths have been rewritten to `CG/venv`; if the venv is ever moved again, rewrite them the same way or recreate it.
- The OpenCV scripts (`Aula5/aula4_algoritmo_de_bresenham_opencv.py`, `Aula5/aula4_braco_robotico.py`) need `cv2`, installed in the venv as `opencv-python` 5.0.0.93. They pass **RGB** tuples to the `cv2.*` calls and display with `plt.imshow`, rather than OpenCV's usual BGR + `cv2.imshow` — keep that convention when editing them.

Most scripts end in `plt.show()` and block on a GUI window. `Aula2Polignos/plano.py` additionally waits for three mouse clicks on the canvas before it draws anything — it cannot be exercised headlessly.

## Structure and progression

The directories follow the course sequence; each one re-implements a graphics primitive from scratch, then usually shows the library equivalent for contrast:

- `Aula2Polignos/plano.py` — matplotlib canvas as a "logical device"; captures mouse input via `mpl_connect('button_press_event')` and builds a `patches.Polygon` from 3 clicked points.
- `Aula4/` — raster vs. vector. `arq.py` rasterizes a circle pixel-by-pixel with Pillow `putpixel` and a squared-distance test; `vetorizada.py` emits the same circle as hand-written SVG text; `rasterizacao_vetorizacao.py` DDA-steps a line into a numpy framebuffer and plots ideal vector vs. pixel grid side by side.
- `Aula5/` — Bresenham line drawing implemented by hand on a numpy array, plus the OpenCV primitives version.
- `Aula6_Cores/` — RGB→CMYK conversion math and Pillow images in both color modes (CMYK must be saved as JPEG; PNG cannot hold it).
- `Slides/` — course PDFs, reference only.

Scripts share no code: each is self-contained with a `main()` guarded by `if __name__ == "__main__"`, and framebuffers are always raw numpy arrays or Pillow `Image` objects, never an abstraction layer. Don't refactor toward shared modules unless asked — the duplication is pedagogical.

## Git

`CG/` is currently untracked in the parent `Faculdade` repo, and `venv/` (195 MB) is not covered by `../.gitignore`. Exclude `venv/` explicitly before staging anything here.
