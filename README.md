# charge-station

Dev pi pico environment in C for vscode

# Usage

- Clone or [download zip](https://github.com/xackery/charge-station/archive/refs/heads/main.zip) of this repo.
- Edit Makefile top line `NAME := charge-station` renaming it to your project's name.
- Bottom left corner of vscode, reopen in dev container.
- Run `make deps` to download deps folder.
- Run `make deps-install` to install dependencies in container (this will take a while).
- Run `make build`, it will create a build subfolder, and prepare cmake for environment.
- Your binaries will be copied to bin/, explore it for various files to copy to your pico!