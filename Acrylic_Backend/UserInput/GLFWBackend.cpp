//
// Created by Corbin Estes on 3/11/20.
//

#include "GLFWBackend.h"


void GLFWBackend::setOnKey(std::function<void (GLFWwindow*, int, int, int, int)> keyCallback) {
    glfwSetKeyCallback(Plexi::getWindowRef(), keyCallback);
}

void GLFWBackend::setOnMouseButton(std::function<void (GLFWwindow *, int, int, int)> mouseCallback){
    glfwSetMouseButtonCallback(Plexi::getWindowRef(), mouseCallback);
}

void GLFWBackend::setOnMouseMove(std::function<void (GLFWwindow *, double, double)> cursorCallback)  {
    glfwSetCursorPosCallback(Plexi::getWindowRef(), cursorCallback);
}

void GLFWBackend::addToKeyMap(int key, int mod, int act, KeyTriple A2D) {
    KeyTriple triple = KeyTriple(key, mod, act);
    modMap.insert(std::pair(triple, A2D));
}

KeyTriple GLFWBackend::convertKeyToA2DCode(int key, int mod, int act) {
    KeyTriple triple = KeyTriple(key, mod, act);
    return modMap.at(triple);
}

void GLFWBackend::keyFunc(GLFWwindow*, int key, int scancode, int mods, int action){
    KeyTriple keyTriple(key, mods, action);
    keyboard.check(keyTriple);
}
void GLFWBackend::mouseButtonFunc(GLFWwindow*, int button, int action, int mods){
    mouse.check(button);
}
void GLFWBackend::mouseMoveFunc(GLFWwindow*, double x, double y){
    A2D_coordPair pair(x, y);
    mouse.cursorMove(pair);
}

void GLFWBackend::init(){
    glfwSetKeyCallback(Plexi::getWindowRef(), keyFunc);
    glfwSetCursorPosCallback(Plexi::getWindowRef(), mouseMoveFunc);
    glfwSetMouseButtonCallback(Plexi::getWindowRef(), mouseButtonFunc);
}
