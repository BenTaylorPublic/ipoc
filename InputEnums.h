#pragma once

#define AMOUNT_OF_PHYSICAL_BUTTONS 98

/*
An enum used for every key on the keyboard
*/
enum Key
{
    A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14, P = 15, Q = 16, R = 17, S = 18, T = 19, U = 20, V = 21, W = 22, X = 23, Y = 24, Z = 25,
    Num0 = 26, Num1 = 27, Num2 = 28, Num3 = 29, Num4 = 30, Num5 = 31, Num6 = 32, Num7 = 33, Num8 = 34, Num9 = 35,
    Numpad0 = 36, Numpad1 = 37, Numpad2 = 38, Numpad3 = 39, Numpad4 = 40, Numpad5 = 41, Numpad6 = 42, Numpad7 = 43, Numpad8 = 44, Numpad9 = 45,
    ArrowLeft = 46, ArrowRight = 47, ArrowUp = 48, ArrowDown = 49,
    F1 = 50, F2 = 51, F3 = 52, F4 = 53, F5 = 54, F6 = 55, F7 = 56, F8 = 57, F9 = 58, F10 = 59, F11 = 60, F12 = 61,
    Add = 62, Subtract = 63, Divide = 64, Multiply = 65,
    EscapeKey = 66, BackSlash = 67, BackSpace = 68, Comma = 69, Dash = 70, Delete = 71, Equal = 72, Home = 73, Insert = 74,
    LAlt = 75, LBracket = 76, LControl = 77, LShift = 78, LSystem = 79, Menu = 80, PageUp = 81, PageDown = 82, Pause = 83, Period = 84, Quote = 85,
    RAlt = 86, RBracket = 87, RControl = 88, Return = 89, RShift = 90, RSystem = 91, SemiColon = 92, Slash = 93, SpaceBar = 94, Tab = 95, Tilde = 96, End = 97
};

/*
An enum used for the different mouse inputs
*/
enum Mouse
{
    LeftButton = 0, MiddleButton = 1, RightButton = 2
};

/*
An enum used for the different statuses a button can be
*/
enum ButtonStatus
{
    ButtonUntouched = 0, ButtonDown = 1, ButtonHold = 2, ButtonUp = 3
};