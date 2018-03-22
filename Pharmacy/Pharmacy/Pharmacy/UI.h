#pragma once

#include "Controller.h"

typedef struct{

	Controller* controller;

}UI;

/// <summary>
/// Creates an UI structure
/// </summary>
/// <param name="controller">Pointer to a specific Controller</param>
/// <returns>A new UI structure</returns>
UI createUI(Controller* controller);


//Functionalities

/// <summary>
/// Adds an element to a specific UI
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void uiAddElement(UI* ui);

/// <summary>
/// Updates an element from a specific UI
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void uiUpdateElement(UI* ui);

/// <summary>
/// Removes an element from a specific UI
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void uiRemoveElement(UI* ui);

/// <summary>
/// Searches an element into a specific UI
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void uiSearchElement(UI* ui);

/// <summary>
/// For a given medication name, see all medications, sorted descending by price.
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void uiDescendingByPriceForMedication(UI* ui);

/// <summary>
/// For a given medication quantity list all medications that have less quantity.
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void uiShortSupply(UI* ui);

/// <summary>
/// For a given medication price, see all medications that have less price.
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void uiCheapMedications(UI* ui);

void uiAscendingByConcentrationForMedication(UI* ui);;


//Others
/// <summary>
/// Prints a simple menu
/// </summary>
void printMenu();

/// <summary>
/// Starts a menu loop for the UI
/// </summary>
/// <param name="ui">Pointer to the coresponding UI</param>
void startUI(UI* ui);

/// <summary>
/// Gets a specific command
/// </summary>
/// <param name="message">A message which will be printed for an specific input</param>
int getCommand(char* message);

/// <summary>
/// Sends a command to the UI
/// </summary>
/// <param name="cmdIndex">A message which will be printed for an specific input</param>
/// <param name="ui">Pointer to the coresponding UI</param>
void executeCommand(int cmdIndex, UI* ui);

/// <summary>
/// Throws a message
/// </summary>
/// <param name="operation">The index of the message to be shown</param>
void printMessage(int operation);


