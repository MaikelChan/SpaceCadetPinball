#include "wii_input.h"

uint32_t wii_input::gcButtonsDown = 0;
uint32_t wii_input::gcButtonsUp = 0;
#ifdef HW_RVL
expansion_t wii_input::wiiExpansion;
uint32_t wii_input::wiiButtonsDown = 0;
uint32_t wii_input::wiiButtonsUp = 0;
#endif

void wii_input::Initialize()
{
    PAD_Init();

#ifdef HW_RVL
    WPAD_Init();
#endif
}

void wii_input::ScanPads()
{
    PAD_ScanPads();
    gcButtonsDown = PAD_ButtonsDown(0);
    gcButtonsUp = PAD_ButtonsUp(0);

#ifdef HW_RVL
    WPAD_ScanPads();
    WPAD_Expansion(0, &wiiExpansion);
    wiiButtonsDown = WPAD_ButtonsDown(0);
    wiiButtonsUp = WPAD_ButtonsUp(0);
#endif
}

bool wii_input::Exit()
{
    bool down = (gcButtonsDown & PAD_TRIGGER_Z);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_HOME); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_HOME); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_HOME);
    };
#endif

    return down;
}

bool wii_input::Pause()
{
    bool down = (gcButtonsDown & PAD_BUTTON_START);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_PLUS); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_PLUS); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_PLUS);
    };
#endif

    return down;
}

bool wii_input::NewGame()
{
    bool down = (gcButtonsDown & PAD_BUTTON_Y);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_MINUS); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & (WPAD_BUTTON_1 | WPAD_BUTTON_MINUS)); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_MINUS);
    };
#endif

    return down;
}

bool wii_input::LaunchBallDown()
{
    bool down = (gcButtonsDown & PAD_BUTTON_A);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_A); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_A); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_2);
    };
#endif

    return down;
}

bool wii_input::LaunchBallUp()
{
    bool up = (gcButtonsUp & PAD_BUTTON_A);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: up |= (wiiButtonsUp & WPAD_CLASSIC_BUTTON_A); break;
        case EXP_NUNCHUK: up |= (wiiButtonsUp & WPAD_BUTTON_A); break;
        default:          up |= (wiiButtonsUp & WPAD_BUTTON_2);
    };
#endif

    return up;
}

bool wii_input::MoveLeftPaddleDown()
{
    bool down = (gcButtonsDown & PAD_TRIGGER_L);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & (WPAD_CLASSIC_BUTTON_FULL_L | WPAD_CLASSIC_BUTTON_ZL)); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_NUNCHUK_BUTTON_Z); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_A);
    };
#endif

    return down;
}

bool wii_input::MoveLeftPaddleUp()
{
    bool up = (gcButtonsUp & PAD_TRIGGER_L);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: up |= (wiiButtonsUp & (WPAD_CLASSIC_BUTTON_FULL_L | WPAD_CLASSIC_BUTTON_ZL)); break;
        case EXP_NUNCHUK: up |= (wiiButtonsUp & WPAD_NUNCHUK_BUTTON_Z); break;
        default:          up |= (wiiButtonsUp & WPAD_BUTTON_A);
    };
#endif

    return up;
}

bool wii_input::MoveRightPaddleDown()
{
    bool down = (gcButtonsDown & PAD_TRIGGER_R);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & (WPAD_CLASSIC_BUTTON_FULL_R | WPAD_CLASSIC_BUTTON_ZR)); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_B); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_1);
    };
#endif

    return down;
}

bool wii_input::MoveRightPaddleUp()
{
    bool up = (gcButtonsUp & PAD_TRIGGER_R);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: up |= (wiiButtonsUp & (WPAD_CLASSIC_BUTTON_FULL_R | WPAD_CLASSIC_BUTTON_ZR)); break;
        case EXP_NUNCHUK: up |= (wiiButtonsUp & WPAD_BUTTON_B); break;
        default:          up |= (wiiButtonsUp & WPAD_BUTTON_1);
    };
#endif

    return up;
}

bool wii_input::NudgeLeftDown()
{
    bool down = (gcButtonsDown & PAD_BUTTON_LEFT);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_LEFT); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_LEFT); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_UP);
    };
#endif

    return down;
}

bool wii_input::NudgeLeftUp()
{
    bool up = (gcButtonsUp & PAD_BUTTON_LEFT);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: up |= (wiiButtonsUp & WPAD_CLASSIC_BUTTON_LEFT); break;
        case EXP_NUNCHUK: up |= (wiiButtonsUp & WPAD_BUTTON_LEFT); break;
        default:          up |= (wiiButtonsUp & WPAD_BUTTON_UP);
    };
#endif

    return up;
}

bool wii_input::NudgeRightDown()
{
    bool down = (gcButtonsDown & PAD_BUTTON_RIGHT);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_RIGHT); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_RIGHT); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_DOWN);
    };
#endif

    return down;
}

bool wii_input::NudgeRightUp()
{
    bool up = (gcButtonsUp & PAD_BUTTON_RIGHT);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: up |= (wiiButtonsUp & WPAD_CLASSIC_BUTTON_RIGHT); break;
        case EXP_NUNCHUK: up |= (wiiButtonsUp & WPAD_BUTTON_RIGHT); break;
        default:          up |= (wiiButtonsUp & WPAD_BUTTON_DOWN);
    };
#endif

    return up;
}

bool wii_input::NudgeUpDown()
{
    bool down = (gcButtonsDown & PAD_BUTTON_UP);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_UP); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_UP); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_RIGHT);
    };
#endif

    return down;
}

bool wii_input::NudgeUpUp()
{
    bool up = (gcButtonsUp & PAD_BUTTON_UP);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: up |= (wiiButtonsUp & WPAD_CLASSIC_BUTTON_UP); break;
        case EXP_NUNCHUK: up |= (wiiButtonsUp & WPAD_BUTTON_UP); break;
        default:          up |= (wiiButtonsUp & WPAD_BUTTON_RIGHT);
    };
#endif

    return up;
}

bool wii_input::SkipError()
{
    bool down = (gcButtonsDown & PAD_BUTTON_A);

#ifdef HW_RVL
    switch (wiiExpansion.type)
    {
        case EXP_CLASSIC: down |= (wiiButtonsDown & WPAD_CLASSIC_BUTTON_A); break;
        case EXP_NUNCHUK: down |= (wiiButtonsDown & WPAD_BUTTON_A); break;
        default:          down |= (wiiButtonsDown & WPAD_BUTTON_2);
    };
#endif

    return down;
}