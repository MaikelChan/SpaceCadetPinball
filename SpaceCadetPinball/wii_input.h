#pragma once

#include <gccore.h>
#ifdef HW_RVL
#include <wiiuse/wpad.h>
#endif

class wii_input
{
public:
    static void Initialize();
    static void ScanPads();

    static bool Exit();
    static bool Pause();
    static bool NewGame();

    static bool LaunchBallDown();
    static bool LaunchBallUp();

    static bool MoveLeftPaddleDown();
    static bool MoveLeftPaddleUp();
    static bool MoveRightPaddleDown();
    static bool MoveRightPaddleUp();

    static bool NudgeLeftDown();
    static bool NudgeLeftUp();
    static bool NudgeRightDown();
    static bool NudgeRightUp();
    static bool NudgeUpDown();
    static bool NudgeUpUp();

    static bool SkipError();

private:
    static uint32_t gcButtonsDown;
    static uint32_t gcButtonsUp;
#ifdef HW_RVL
    static expansion_t wiiExpansion;
    static uint32_t wiiButtonsDown;
    static uint32_t wiiButtonsUp;
#endif
};