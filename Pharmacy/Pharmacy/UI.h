#pragma once

#include "Controller.h"

typedef struct{

	Controller* controller;

}UI;

UI createUI(Controller* controller);
void printMenu();
int getCommand(char* message);
void startUI(UI* ui);

void uiAddElement(UI* ui);
void uiUpdateElement(UI* ui);
void uiRemoveElement(UI* ui);
void uiSearchElement(UI* ui);

void executeCommand(int cmdIndex, UI* ui);
void printMessage(int operation);