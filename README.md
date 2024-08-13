# 3D Pinball - Space Cadet for Wii

This is a port of 3D Pinball - Space Cadet for Nintendo Wii. It's originally a game that came bundled with Windows from Windows 95 up to Windows XP. This is the current state of the project:

- It is compatible with 3D Pinball - Space Cadet and the Space Cadet table from [Full Tilt! Pinball](https://en.wikipedia.org/wiki/Full_Tilt!_Pinball). 
- No menus, options, or results screen.
- Playable with the Wii remote and the GameCube pad.
- It plays sound effects and music (if the player supplies the music in OGG format).
- There are still some bugs here and there, but it's perfectly playable.

It is based on the PC decompilation made by [k4zmu2a](https://github.com/k4zmu2a): https://github.com/k4zmu2a/SpaceCadetPinball

The PC decompilation uses SDL2 to render the game. This Wii port has been changed to use native GPU rendering with the GX library.

I also made the required changes to make the original game's binary assets work in this port. The Wii's CPU is big endian, instead of little endian like PC x86. These changes could be useful for porting to other big endian devices.

## How to build

The main requirement is to have [devkitPro](https://devkitpro.org).

Follow the instructions to install devkitPro here: https://devkitpro.org/wiki/Getting_Started
You will also need the Wii development package, and also the libraries wii-sdl, wii-sdl_mixer and wii-opengx.

If you use Windows or Ubuntu, here are more detailed instructions.

### Windows

Even though devkitPro offers a Windows installer, I've had some issues setting it up. It's easier to use WSL. If you want to use the Windows installer anyway, check the link above for instructions.

1. Install [WSL](https://docs.microsoft.com/en-us/windows/wsl/install). By default it will install Ubuntu, which is fine.
2. Open a WSL terminal and just follow the Ubuntu instructions below. With the difference that, if you want to clone the project into, for example, the `C:\` folder, you will need move to that folder inside the terminal with the command `cd /mnt/c/`.

### Ubuntu and other Debian based linux distros

1. Open the terminal in the folder where you want to clone the project.
2. Clone it with the command `git clone --branch wii https://github.com/MaikelChan/SpaceCadetPinball`. A subfolder called `SpaceCadetPinball` will be created containing the project.
3. Move to that subfolder with `cd SpaceCadetPinball`.
4. Follow the instructions to install the latest version of the [custom devkitPro pacman](https://devkitpro.org/wiki/devkitPro_pacman), that will be used to download the compilers and libraries to build the project.
5. Use the following command to sync pacman databases: `sudo dkp-pacman -Sy`.
6. Now update packages with `sudo dkp-pacman -Syu`.
7. Install the Wii development tools with `sudo dkp-pacman -S wii-dev`.
8. Install SDL with `sudo dkp-pacman -S wii-sdl`.
9. Install SDL_mixer with `sudo dkp-pacman -S wii-sdl_mixer`.
10. Install OpenGX with `sudo dkp-pacman -S wii-opengx`.
11. Set the DEVKITPRO environment variables so the system knows where the compilers and libraries are installed with these commands:
    - `export DEVKITPRO=/opt/devkitpro`.
    - `export DEVKITPPC=/opt/devkitpro/devkitPPC`.
12. Build the project with the command `make -j`.

After a successful build, you will get a file called `SpaceCadetPinball.dol`, which is the main executable.

## How to run

### Wii with homebrew channel

1. Rename `SpaceCadetPinball.dol` to `boot.dol`.
2. Go to the `sd` folder in this repository, and copy its contents to the root of the SD card you use for loading apps for the Hombrew channel.
3. Copy `boot.dol` to `apps/SpaceCadetPinball/` in your SD card.
4. For legal reasons, you will need to get the original PC game on your own to obtain the assets like graphics and sound effects. Those are not contained in this repository.
5. Copy all PC game's assets to `apps/SpaceCadetPinball/Data/` in your SD card. For `Full Tilt! Pinball`, copy all the files and the `SOUND` folder that are located inside the `CADET` folder.
6. Optionally, since this port doesn't play MIDI files, you'll need to convert the music to ogg format. Make sure that the music has a sample rate no higher than 44100Hz, or it won't play correctly:
    - 3D Pinball - Space Cadet: name the file `PINBALL.ogg` and put it along the other assets in the `Data` folder.
    - Full Tilt! Pinball: name the file `TABA1.ogg` and put it along the other sound files in the `Data/SOUND` folder.
7. If everything went fine, you should be able to see the game in your homebrew channel and run it.

### Dolphin

1. Get the [Dolphin emulator](https://dolphin-emu.org) if you don't have it.
2. Create and edit a virtual SD card following [these instructions](https://wiki.dolphin-emu.org/index.php?title=Virtual_SD_Card_Guide).
3. Mount that virtual card.
4. Follow the steps 4, 5 and 6 in `Wii with homebrew channel` section.
5. Unmount the SD card, as Dolphin won't be able to access its contents while it's mounted.
6. Open Dolphin, go to `Config`, then to the `Audio` tab, and select `DSP LLE REcompiler (slow)`. Audio won't work without that.
7. Go to `Graphics` settings, then to the `Hacks` tab, and move the `Accuracy` slider all the way to the left to set it as `Safe`.
8. Go to the menu `File` and then `Open...`.
9. Locate and open `SpaceCadetPinball.dol` (or `boot.dol` in case you renamed it for the homebrew channel).
10. If everything went fine, you should be able to run the game.

## How to play

### Wii Remote
```
2                    :  Launch the ball
A                    :  Move the left paddle
1                    :  Move the right paddle
DPAD Left, Right, Up :  Bump table
-                    :  Start a new game
+                    :  Pause
```

### Nunchuk
```
A                    :  Launch the ball
Z                    :  Move the left paddle
B                    :  Move the right paddle
DPAD Left, Right, Up :  Bump table
-                    :  Start a new game
+                    :  Pause
```

### Classic Controller
```
A                    :  Launch the ball
L/ZL                 :  Move the left paddle
R/ZR                 :  Move the right paddle
DPAD Left, Right, Up :  Bump table
-                    :  Start a new game
+                    :  Pause
```

### GameCube Pad
```
A                    :  Launch the ball
L                    :  Move the left paddle
R                    :  Move the right paddle
DPAD Left, Right, Up :  Bump table
Y                    :  Start a new game
Start                :  Pause
```

## Screenshots

<p align="center">
  <img title="3D Pinball - Space Cadet for Wii running on Dolphin Emulator" src="/screenshot00.png">
</p>