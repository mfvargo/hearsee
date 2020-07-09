/*
 * HearSee audio effect based on DISTRHO Plugin Framework (DPF)
 *
 * SPDX-License-Identifier: MIT
 *
 * Copyright (C) 2020 Mike Vargo <mfvargo@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "UIHearSee.hpp"
#include "Window.hpp"

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------
// Init / Deinit

UIHearSee::UIHearSee()
: UI(600, 400)  {

}

UIHearSee::~UIHearSee() {

}

// -----------------------------------------------------------------------
// DSP/Plugin callbacks

/**
  A parameter has changed on the plugin side.
  This is called by the host to inform the UI about parameter changes.
*/
void UIHearSee::parameterChanged(uint32_t index, float value) {
    switch (index) {
        case PluginHearSee::paramGain:
            // do something when Gain param is set, such as update a widget
            break;
    }

    (void)value;
}

/**
  A program has been loaded on the plugin side.
  This is called by the host to inform the UI about program changes.
*/
void UIHearSee::programLoaded(uint32_t index) {
    if (index < presetCount) {
        for (int i=0; i < PluginHearSee::paramCount; i++) {
            // set values for each parameter and update their widgets
            parameterChanged(i, factoryPresets[index].params[i]);
        }
    }
}

/**
  Optional callback to inform the UI about a sample rate change on the plugin side.
*/
void UIHearSee::sampleRateChanged(double newSampleRate) {
    (void)newSampleRate;
}

// -----------------------------------------------------------------------
// Optional UI callbacks

/**
  Idle callback.
  This function is called at regular intervals.
*/
void UIHearSee::uiIdle() {

}

/**
  Window reshape function, called when the parent window is resized.
*/
void UIHearSee::uiReshape(uint width, uint height) {
    (void)width;
    (void)height;
}

// -----------------------------------------------------------------------
// Widget callbacks


/**
  A function called to draw the view contents with NanoVG.
*/
void UIHearSee::onNanoDisplay() {

}


// -----------------------------------------------------------------------
// Optional widget callbacks; return true to stop event propagation, false otherwise.

/**
  A function called when a key is pressed or released.
*/
bool UIHearSee::onKeyboard(const KeyboardEvent& ev) {
    return false;
    (void)ev;
}

/**
  A function called when a special key is pressed or released.
*/
bool UIHearSee::onSpecial(const SpecialEvent& ev) {
    return false;
    (void)ev;
}

/**
  A function called when a mouse button is pressed or released.
*/
bool UIHearSee::onMouse(const MouseEvent& ev) {
    return false;
    (void)ev;
}

/**
  A function called when the mouse pointer moves.
*/
bool UIHearSee::onMotion(const MotionEvent& ev) {
    return false;
    (void)ev;
}

/**
  A function called on scrolling (e.g. mouse wheel or track pad).
*/
bool UIHearSee::onScroll(const ScrollEvent& ev) {
    return false;
    (void)ev;
}

// -----------------------------------------------------------------------

UI* createUI() {
    return new UIHearSee();
}

// -----------------------------------------------------------------------

END_NAMESPACE_DISTRHO
