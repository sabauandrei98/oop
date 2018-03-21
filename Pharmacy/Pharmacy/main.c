#include "UI.h"
#include "Controller.h"
#include "Repository.h"
#include "Medication.h"
#include <crtdbg.h>

void initialData(Controller* myController)
{

	controllerAddElement(myController, createMedication("Raceala", 60,  0, 150));
	controllerAddElement(myController, createMedication("Raceala", 65, 20, 500));
	controllerAddElement(myController, createMedication("Raceala", 20, 30, 300));
	controllerAddElement(myController, createMedication("Febra1", 10,  0, 50));
	controllerAddElement(myController, createMedication("Febra2", 20,  0, 100));
	controllerAddElement(myController, createMedication("Gripa", 15,  0, 250));
	controllerAddElement(myController, createMedication("Stomac", 30,  0, 35));
	controllerAddElement(myController, createMedication("Digestie1", 80,  0, 2000));
	controllerAddElement(myController, createMedication("Digestie2", 90, 20, 2500));
	controllerAddElement(myController, createMedication("Digestie3", 95, 3, 3000));
	controllerAddElement(myController, createMedication("Digestie4", 100, 4, 3850));
	controllerAddElement(myController, createMedication("Glicemie1", 50, 3, 5));
	controllerAddElement(myController, createMedication("Glicemie2", 60, 8, 15));
}

void runTests()
{
	medicationTest();
	repositoryTest();
	controllerTest();
}

int main()
{
	//PROGRAM TESTS
	runTests();
	//////////
	
	DynamicRepo* pharmaRepo = createDynamicArray(20);
	Controller pharmaController = createController(pharmaRepo);
	UI pharmaUI = createUI(&pharmaController);

	////INITIAL SETUP DATA
	initialData(&pharmaController);
	printRepository(pharmaRepo);
	//////////////////////


	startUI(&pharmaUI);
	
	system("pause");
	_CrtDumpMemoryLeaks();

	return 0;
}