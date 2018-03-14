#pragma once

#include "Controller.h"

typedef struct{

	Controller* controller;

}UI;

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="controller">Integer, maximum capacity for the dynamic array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
UI createUI(Controller* controller);

void printMenu();
void startUI(UI* ui);
int getCommand(char* message);
void executeCommand(int cmdIndex, UI* ui);
void printMessage(int operation);


void uiAddElement(UI* ui);
void uiUpdateElement(UI* ui);
void uiRemoveElement(UI* ui);
void uiSearchElement(UI* ui);


