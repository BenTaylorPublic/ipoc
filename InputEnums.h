#pragma once

#define AMOUNT_OF_PHYSICAL_BUTTONS 103

/*
An enum used for every physical button
*/
enum PhysicalButton
{
    KeyA = 0, KeyB = 1, KeyC = 2, KeyD = 3, KeyE = 4, KeyF = 5, KeyG = 6, KeyH = 7, KeyI = 8, KeyJ = 9, KeyK = 10, KeyL = 11, KeyM = 12, KeyN = 13, KeyO = 14, KeyP = 15, KeyQ = 16, KeyR = 17, KeyS = 18, KeyT = 19, KeyU = 20, KeyV = 21, KeyW = 22, KeyX = 23, KeyY = 24, KeyZ = 25,
    Key0 = 26, Key1 = 27, Key2 = 28, Key3 = 29, Key4 = 30, Key5 = 31, Key6 = 32, Key7 = 33, Key8 = 34, Key9 = 35,
    Numpad0 = 36, Numpad1 = 37, Numpad2 = 38, Numpad3 = 39, Numpad4 = 40, Numpad5 = 41, Numpad6 = 42, Numpad7 = 43, Numpad8 = 44, Numpad9 = 45,
    KeyArrowLeft = 46, KeyArrowRight = 47, KeyArrowUp = 48, KeyArrowDown = 49,
    KeyF1 = 50, KeyF2 = 51, KeyF3 = 52, KeyF4 = 53, KeyF5 = 54, KeyF6 = 55, KeyF7 = 56, KeyF8 = 57, KeyF9 = 58, KeyF10 = 59, KeyF11 = 60, KeyF12 = 61,
    KeyAdd = 62, KeySubtract = 63, KeyDivide = 64, KeyMultiply = 65,
    KeyEscape = 66, KeyBackSlash = 67, KeyBackSpace = 68, KeyComma = 69, KeyDash = 70, KeyDelete = 71, KeyEqual = 72, KeyHome = 73, KeyInsert = 74,
    KeyLAlt = 75, KeyLBracket = 76, KeyLControl = 77, KeyLShift = 78, KeyLSystem = 79, KeyMenu = 80, KeyPageUp = 81, KeyPageDown = 82, KeyPause = 83, KeyPeriod = 84, KeyQuote = 85,
    KeyRAlt = 86, KeyRBracket = 87, KeyRControl = 88, KeyReturn = 89, KeyRShift = 90, KeyRSystem = 91, KeySemiColon = 92, KeySlash = 93, KeySpaceBar = 94, KeyTab = 95, KeyTilde = 96, KeyEnd = 97,
    MouseLeft = 98, MouseRight = 99, MouseMiddle = 100, MouseXButton1 = 101, MouseXButton2 = 102
};

/*
An enum used for the different statuses a button can be
*/
enum ButtonStatus
{
    ButtonUntouched = 0, ButtonDown = 1, ButtonHold = 2, ButtonUp = 3
};