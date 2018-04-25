#include "Tests.h"
#include "Controller.h"
#include <assert.h>


Tests::Tests()
{
}


Tests::~Tests()
{
}

void Tests::controllerTest()
{
	Repository repository;

	Controller controller{ repository };
	Dog dog1("Breed1", "Name1", 10, "www.google.ro");
	controller.addController(dog1);

	Dog dog2("Breed2", "Name2", 20, "www.google.ro");
	controller.addController(dog2);

	Dog dog3("Breed3", "Name3", 30, "www.google.ro");
	controller.addController(dog3);

	Dog dog4("Breed4", "Name4", 40, "www.google.ro");
	controller.addController(dog4);

	Repository repo = controller.getRepository();
	assert(repo.getDynamicArray().getSize() == 4);
	Repository adoptionRepo = controller.getAdoptionRepository();
	assert(adoptionRepo.getDynamicArray().getSize() == 0);

	controller.addAdoptionController(dog1);
	assert(controller.getAdoptionRepository().getDynamicArray().getSize() == 1);

	controller.deleteController(dog2);
	assert(controller.getRepository().getElementPosition(dog2) == -1);

	controller.updateController(dog3, dog1);
	repo = controller.getRepository();
	DynamicArray<Dog> da = repo.getDynamicArray();
	vector<Dog> dogs = da.getAllElems();
	assert(dogs[1].getName() == "Name1");

	da = controller.getSpecificDogs(dog1);
	assert(da.getSize() == 2);
}

void Tests::repositoryTest()
{
	Repository repo;

	Dog dog1("Breed1", "Name1", 10, "www.google.ro");
	repo.addRepository(dog1);

	Dog dog2("Breed2", "Name2", 20, "www.google.ro");
	repo.addRepository(dog2);

	Dog dog3("Breed3", "Name3", 30, "www.google.ro");
	repo.addRepository(dog3);

	Dog dog4("Breed4", "Name4", 40, "www.google.ro");
	repo.addRepository(dog4);

	Dog dog5("Breed4", "Name6", 40, "www.google.ro");
	repo.addRepository(dog5);


	int pos = repo.getElementPosition(dog1);
	repo.deleteRepository(pos);

	assert(repo.getDynamicArray().getSize() == 4);

	pos = repo.getElementPosition(dog4);
	repo.updateRepository(pos, dog1);

	pos = repo.getElementPosition(dog1);
	repo.deleteRepository(pos);
	assert(repo.getDynamicArray().getSize() == 3);
}

void Tests::dynamicArrayTest()
{
	
	DynamicArray<Dog> dr1;

	assert(dr1.getSize() == 0);

	Dog dog{ "breed1", "name1", 20, "photo1" };
	dr1.addDynamicArray(dog);

	assert(dr1.getSize() == 1);

	Dog dog1{ "breed2", "name2", 40, "photo3" };
	DynamicArray<Dog> dr2;
	dr2.addDynamicArray(dog1);

	dr1 = dr1 + dr2;

	assert(dr1.getSize() == 2);
	vector<Dog> elems = dr1.getAllElems();
	assert(elems[0].getName() == "name1");
	assert(elems[1].getName() == "name2");

	dr1.updateDynamicArray(0, dog1);
	elems = dr1.getAllElems();
	
	assert(elems[0].getName() == "name2");
	dr1.deleteDynamicArray(1);
	dr1.deleteDynamicArray(0);
	assert(dr1.getSize() == 0);
	
	dr2.addDynamicArray(dog1);
	dr2.printArray();

	

	Dog dog2("Breed2", "Name2", 20, "www.google.ro");
	dr2.addDynamicArray(dog2);

	Dog dog3("Breed3", "Name3", 30, "www.google.ro");
	dr2.addDynamicArray(dog3);

	Dog dog4("Breed4", "Name4", 40, "www.google.ro");
	dr2.addDynamicArray(dog4);

	Dog dog5("Breed4", "Name6", 40, "www.google.ro");
	dr2.addDynamicArray(dog5);

	dr1 = dr1 + dr2;
}

void Tests::dogTest() 
{
	Dog emptyDog{};
	assert(emptyDog.getBreed() == "");
	assert(emptyDog.getName() == "");

	Dog dog{"breed","name", 10, "www.google.ro"};
	dog.printDog();
	assert(dog.getBreed() == "breed");
	assert(dog.getName() == "name");
	assert(dog.getPhotograph() == "www.google.ro");
	assert(dog.getAge() == 10);
}

void Tests::sortingTest() {
	Repository repo;
	
	Dog dog1("Breed1", "Name1", 55, "www.google.ro");
	repo.addRepository(dog1);

	Dog dog2("Breed2", "Name9", 60, "www.google.ro");
	repo.addRepository(dog2);

	Dog dog3("Breed3", "Name3", 30, "www.google.ro");
	repo.addRepository(dog3);

	Dog dog4("Breed4", "Name4", 40, "www.google.ro");
	repo.addRepository(dog4);

	Dog dog5("Breed4", "Name6", 40, "www.google.ro");
	repo.addRepository(dog5);

	SortByAgeDescending<Dog> sortByAge;
	DynamicArray<Dog> myArray = repo.sortArray(sortByAge);
	vector<Dog> elems = myArray.getAllElems();
	myArray.printArray();
	assert(elems[4].getAge() == 30);
	assert(elems[3].getAge() == 40);
	assert(elems[2].getAge() == 40);
	assert(elems[1].getAge() == 55);
	assert(elems[0].getAge() == 60);

	SortByNameAscending<Dog> sortByName;
	myArray = repo.sortArray(sortByName);
	elems = myArray.getAllElems();
	assert(elems[0].getName() == "Name1");
	assert(elems[1].getName() == "Name3");
	assert(elems[2].getName() == "Name4");
	assert(elems[3].getName() == "Name6");
	assert(elems[4].getName() == "Name9");
}

void Tests::runTests() {
	try {
		this->controllerTest();
		this->repositoryTest();
		this->dynamicArrayTest();
		this->dogTest();
		this->sortingTest();
	}
	catch (Exceptions ex)
	{
		ex.printException();
	}
}
