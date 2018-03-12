#include "UI.h"
#include "Controller.h"
#include "Repository.h"
#include "Medication.h"


void initialData(DynamicRepo* myRepo)
{
	addElement(myRepo, createMedication("med1", 10, 20, 30));
	addElement(myRepo, createMedication("med2", 10, 20, 30));
	addElement(myRepo, createMedication("med3", 10, 20, 30));
	addElement(myRepo, createMedication("med4", 10, 20, 30));
	addElement(myRepo, createMedication("med5", 10, 20, 30));
	addElement(myRepo, createMedication("med6", 10, 20, 30));
	addElement(myRepo, createMedication("med7", 10, 20, 30));
	addElement(myRepo, createMedication("med8", 10, 20, 30));
	addElement(myRepo, createMedication("med9", 10, 20, 30));
	addElement(myRepo, createMedication("med10", 10, 20, 30));
	addElement(myRepo, createMedication("med3", 10, 20, 30));
	addElement(myRepo, createMedication("med4", 10, 20, 30));
	addElement(myRepo, createMedication("med5", 10, 20, 30));
	addElement(myRepo, createMedication("med6", 10, 20, 30));
	addElement(myRepo, createMedication("med7", 10, 20, 30));
	addElement(myRepo, createMedication("med8", 10, 20, 30));
	addElement(myRepo, createMedication("med9", 10, 20, 30));
	addElement(myRepo, createMedication("med10", 10, 20, 30));
	addElement(myRepo, createMedication("med3", 10, 20, 30));
	addElement(myRepo, createMedication("med4", 10, 20, 30));
	addElement(myRepo, createMedication("med5", 10, 20, 30));
	addElement(myRepo, createMedication("med6", 10, 20, 30));
	addElement(myRepo, createMedication("med7", 10, 20, 30));
	addElement(myRepo, createMedication("med8", 10, 20, 30));
	addElement(myRepo, createMedication("med9", 10, 20, 30));
	addElement(myRepo, createMedication("med10", 10, 20, 30));
}

int main()
{
	DynamicRepo* pharmaRepo = createDynamicRepo(20);
	Controller pharmaController = createController(pharmaRepo);
	UI pharmaUI = createUI(&pharmaController);

	//INITIAL SETUP
	initialData(pharmaRepo);
	repositoryToString(pharmaRepo);

	startUI(&pharmaUI);
	
	system("pause");
	return 0;
}