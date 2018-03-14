#include "UI.h"
#include "Controller.h"
#include "Repository.h"
#include "Medication.h"


void initialData(DynamicRepo* myRepo)
{
	addElement(myRepo, createMedication("Raceala1", 10,  0, 150));
	addElement(myRepo, createMedication("Raceala2", 15, 20, 200));
	addElement(myRepo, createMedication("Raceala3", 20, 30, 300));
	addElement(myRepo, createMedication("Febra1", 10,  0, 50));
	addElement(myRepo, createMedication("Febra2", 20,  0, 100));
	addElement(myRepo, createMedication("Gripa", 15,  0, 250));
	addElement(myRepo, createMedication("Stomac", 30,  0, 35));
	addElement(myRepo, createMedication("Digestie1", 80,  0, 2000));
	addElement(myRepo, createMedication("Digestie2", 90, 20, 2500));
	addElement(myRepo, createMedication("Digestie3", 95, 3, 3000));
	addElement(myRepo, createMedication("Digestie4", 100, 4, 3850));
	addElement(myRepo, createMedication("Glicemie1", 50, 3, 5));
	addElement(myRepo, createMedication("Glicemie2", 60, 8, 15));
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
	
	DynamicRepo* pharmaRepo = createDynamicRepo(20);
	Controller pharmaController = createController(pharmaRepo);
	UI pharmaUI = createUI(&pharmaController);

	////INITIAL SETUP DATA
	initialData(pharmaRepo);
	repositoryToString(pharmaRepo);
	//////////////////////

	startUI(&pharmaUI);
	
	system("pause");
	return 0;
}