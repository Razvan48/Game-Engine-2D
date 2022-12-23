/*
    
	GAME ENGINE 2D

    AUTOR: CAPATINA RAZVAN NICOLAE

	NUME PROIECT: GAME ENGINE 2D
	NUME FISIER HEADER: "GameEngine2D.h"

	VERSIUNE: 1.0

	ULTIMA DATA A FOST REVIZUIT PE: 1 IANUARIE 2021

	CE ESTE EL?

		ACESTA ESTE UN GAME ENGINE CE POATE CONTRIBUI LA:

			CREAREA UNUI JOC CE SE DESFASOARA IN SPATIU 2D / BIDIMENSIONAL.
			VIZUALIZAREA UNOR ALGORITMI.

	DE CE EXISTA? CE SCOP / SCOPURI ARE?

		- SA CONTRIBUIE LA CONSTRUCTIA UNUI JOC / UNEI APLICATII CE SE DESFASOARA IN SPATIU 2D / BIDIMENSIONAL;

		- SA AJUTE ALTE PERSOANE SA SE DEZVOLTE IN DOMENIU;

		- SA MOTIVEZE ALTE PERSOANE SA INCERCE SA CONSTRUIASCA PROIECTE INTERESANTE,
		  GAME ENGINE-UL OFERIND O INTERFANTA PRIETENOASA SI ASCUNZAND DETALIILE DE IMPLEMENTARE CE POT FI COMPLICATE;

		- SA MA AJUTE PE MINE IN VIITOR CU DIVERSE APLICATII 2D;

	PLATFORME PE CARE FUNCTIONEAZA:
		
		PERSONAL COMPUTER (PC)

	COMENTARIILE AUTORULUI:

		ACEST "GAME ENGINE 2D" (OARECUM) E UN PROIECT PRIN CARE AM INVATAT FOARTE MULTE LUCRURI NOI IN CEEA CE PRIVESTE C++ 
	(MAI ALES CUM FUNCTIONEAZA UN ENTITY / COMPONENT BASED SYSTEM / ARCHITECTURE SI, DE ASEMENEA, CONCEPTUL DE CLASA DE BAZA
	SI CLASA DERIVATA SI MOSTENIREA DE / INTRE CLASE, LUCRURI CE MI-AU PERMIS SA ORGANIZEZ CODUL LA UN CU TOTUL ALT NIVEL)
	SI OPENGL.
		DE ASEMENEA, AM LUAT ACEST PROIECT MAI MULT CA PE O PROVOCARE PENTRU MINE, PENTRU A VEDEA CAT DE DEPARTE POT IL POT DEZVOLTA
	SI CARE SUNT LIMITELE MELE IN ACEST DOMENIU.
		
		PRIORITATEA PE CARE AM AVUT-O CAND AM SCRIS ACEST FISIER HEADER A FOST SA GASESC UN ECHILIBRU INTRE SIMPLITITATE, PERFORMANTA
	SI COMUNICAREA DINTRE UTILIZATOR SI PROGRAM (PRIN ASTA VREAU SA SPUN CA AM PUS SI EU 2-3 MESAJE FOARTE CLARE IN CAZ CA ARE LOC UNA
	DINTRE ERORILE PE CARE LE CONSIDER EU FRECVENTE. DE ASEMENEA, MI-AM DORIT SA ASCUND TOATE DETALIILE DE IMPLEMENTARE CE POT FI CONSIDERATE
	COMPLICATE. ASTFEL, O PERSOANA CE FOLOSESTE ACEST GAME ENGINE VA FI NEVOITA DOAR SA INCLUDA ACEST HEADER FILE (DE APROXIMATIV 2300 DE LINII
	LA MOMENTUL SCRIERII ACESTEI INTRODUCERI) IN "main.cpp", SA INCARCE RESURSELE (SUNETELE (LE VOI AVEA IN CURAND, SPER...), TEXTURILE,
	ENTITATILE, HITBOX-URILE, TEXTURE BOX-URILE) SI DOAR SA SCRIE CATEVA LINII DE COD PENTRU A CREA UN JOC 2D CHIAR INTERESANT,
	RESTUL FIIND GESTIONAT AUTOMAT.
		GAME ENGINE-UL AR TREBUI SA FIE USOR DE FOLOSIT, CHIAR DACA UTILIZATORUL NU INTELEGE IN TOTALITATE CUM FUNCTIONEAZA EL INTERN,
	DEOARECE AM INCERCAT SA PASTREZ O INTERFATA PRIETENOASA (SI INTRE TIMP AM PIERDUT PUTINA PERFORMANTA SI VITEZA FACAND ASTA, DAR AIA E).

	PROBLEME DE CARE SUNT CONSTIENT CA ACEST GAME ENGINE LE ARE SI PE CARE PROBABIL NU LE VOI REZOLVA DIN LIPSA DE MOTIVATIE / DOCUMENTARE / CUNOASTERE SAU DIN PURA LENE:

		- UTILIZATORUL POATE ATASA UNEI ENTITATI O CLASA CE NU ESTE DE FAPT O COMPONENTA DERIVATA DIN COMPONENTA DE BAZA, VIRTUALA, CEEA CE NU ESTE OK (ACEST LUCRU VA REZULTA
		  IN CRAPAREA PROGRAMULUI SI APARITIA UNEI ERORI DAR MESAJUL EI NU VA FI DELOC CLAR SI NU VA REZULTA CA ACEASTA AR FI PROBLEMA (ADICA IN CAZ CA APAR ERORI DUBIOASE ASTA
		  POATE FI UN MOTIV SI E BINE DE STIUT));

		- COLIZIUNEA INTRE ENTITATI ESTE UN ALGORITM AABB (AXIS-ALIGNED-BOUNDING-BOX) STATIC (ADICA CAT TIMP UTILIZATORUL NU DA VITEZE PREA MARI ENTITATILOR SI CAT TIMP UTILIZATORUL
		  ARE FRAME RATE OK SI NU RULEAZA PROGRAMUL PE UN CARTOF SI NU SE EXAGEREAZA CU NUMARUL DE ENTITATI CREATE TOTUL AR TREBUI SA FIE OK);

		- DACA O ENTITATE ARE O COMPONENTA DE ANIMATIE SI PROGRAMUL E OBLIGAT PRIN CE SE INTAMPLA IN APLICATIE SA RULEZE O ANIMATIE ANUME, DAR UTILIZATORUL NU A ATASAT NICIO ANIMATIE
		  IN ACEL SCENARIU (DOAR A ATASAT COMPONENTA), ATUNCI PROGRAMUL VA CRAPA SI NU VA FI CLAR DE CE, MESAJUL PRIMIT DE LA EROARE FIIND PUTIN CIUDAT (ADICA IN CAZ DE EROARE FARA
		  SENS SI ASTA POATE FI UN MOTIV PENTRU APARITIA EI);

	MENTIONARI:

		- MAI JOS SUNT DECLARATE TOATE SISTEMELE ENGINE-ULUI, ENTITATILE, COMPONENTELE SI ALTE PROSTII PLICTISITOARE, ETC. AR FI DE FOLOS PENTRU UTILIZATOR DOAR SA CITEASCA CE CLASE SUNT COMPONENTE PENTRU ENTITATI
		  (ADICA CE CLASE DERIVA DIN CLASA DE BAZA / FUNDAMENTALA, COMPONENTA) SI DE CE SISTEME DE ENTITATI DISPUNE ENGINE-UL;
		- TEXTURILE PE CARE LE VA INCARCA GAME ENGINE-UL AR TREBUI FIE DE 400 PE 400 DE PIXELI (400 X 400) (CEL PUTIN ASA AM VAZUT CA SE COMPORTA OK);

		- ORICE POZITIE, DIRECTIE, VIZTEZA, ACCELERATIE, FORTA (ORICE MARINE CE POATE FI REPREZENTATA CA UN VECTOR 2D PE SCURT) ARE ORIGINEA O(0, 0) IN COLTUL DE JOS DIN STANGA AL FERESTREI JOCULUI,
		  AXA OX LUAND VALORI POZITIVE CATRE DREAPTA SI AXA OY IN SUS. O CONSECINTA A ACESTUI LUCRU E CA ACCELERATIE GRAVITATIONALA VA TREBUI SA FIE NEGATIVA PENTRU A AVEA UN EFECT NORMAL
		  (PENTRU A ATRAGE O ENTITATE IN JOS) (PRACTIC E OPUSUL CONVENTIEI DE LA FIZICA CU GRAVITATIA POZITIVA, ETC.). DOAR SISTEMUL DE COORDONATE AL TEXTURILOR ARE ORIGINEA IN COLTUL DE SUS, NU JOS, DIN STANGA,
		  AXA OX LUAND VALORI POZITIVE LA DREAPTA, IAR AXA OY IN JOS (ASTA NU CONTEAZA PREA MULT, DEOARECE GAME ENGINE-UL VA GESTIONA TEXTURILE SI UTILIZATORUL DOAR LE VA INCARCA);

		- IN APLICATIA ASTA ENTIATILE DE TIPUL "CARACTER" (PERSONAJ) NU SE VOR INTERSECTA INTRE ELE (POATE DA, DAR NU SE VOR RESPINGE, VAD EU CE FAC).
		  IN SCHIMB VA EXISTA COLIZIUNE INTRE TEREN SI ORICE CARACTER / PERSONAJ SI INTRE CARACTER / PERSONAJ SI GLOANTE;

*/

#pragma once // ASA INCEPE ORICE PROIECT CE VA AJUNGE SA ISI PIARDA SENSUL CU CAT SE DEZVOLTA

// INCLUDERE OPENGL (GAME ENGINE-UL INCLUDE ASTEA, DAR LINKING-UL TREBUIE REALIZAT DE UTILIZATOR SI OPENGL-UL TREBUIE ATASAT SEPARAT LA PROIECTUL CE FOLOSESTE ACEST HEADER. GAME ENGINE-UL NU FACE ASTA.)

#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <SOIL2.h>

// INCLUDERE FUNCTIONALITATI DIN LIBRARIA STANDARD

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>
#include <bitset>

// DECLARAREA TUTUROR CLASELOR (ENUM UNELE), STRUCTURILOR, VARIABILELOR SI A ALTOR LUCRURI

// CLASA PRINCIPALA
class GameEngine;

// SISTEME / MANAGER-E 2D (PRACTIC FIECARE DINTRE ACESTEA GESTIONEAZA ENTITATILE CE AU COMPONENTA LOR RESPECTIVA)
class WindowManager;
class TimeManager;
class InputManager;
class AssetManager;
class MovementManager;
class CollisionManager;
class AnimationManager;

class Camera; // CLASA CAMERA

class BehaviourManager;

// STOCARE DE ENTITATI

class CharacterStorage;
class TerrainStorage;
class ProjectileStorage;
class LandscapeStorage;
class HitboxStorage;
class SpeedStorage;
class AnimationStorage;
class BehaviourStorage;
class InputStorage;

// RENDERER 2D
class Renderer;

// ENTITATE 2D
class Entity;

// CE TIPURI DE ENTITATI 2D EXISTA
enum class EntityType
{
	character,
	terrain,
	projectile,
	landscape,
};

// COMPONENTA 2D (E CLASA VIRTUALA. TOATE COMPONENTELE 2D CE VOR FI FOLOSITE SE MOSTENESC DIN ACEASTA)
class Component;

// CLASELE COMPONENTELOR CE SE MOSTENESC DIN COMPONENTA DE BAZA, VIRTUALA

class Position;
class Hitbox; // LE SALVAM IN COLLISION MANAGER
class Texture;
class TextureBox;
class Render;
class Speed; // LE SALVAM IN MOVEMENT MANAGER
class Acceleration;
class Gravity;
class Animation; // LE SALVAM IN ANIMATION MANAGER
class MovementSpeed;
class Behaviour; // LE SALVAM IN BEHAVIOUR MANAGER
class Input; // LE SALVAM IN INPUT MANAGER

// IN CE STADIU DE ANIMATIE 2D POT FI ENTITATILE 2D CARE AU ASA CEVA IN PRIMUL RAND
const int MAX_ANIMATIONS_ENTITY = 9;

enum class EntityAnimation
{
	notSet = -1,
	standing = 0,
	walkingRight = 1,
	walkingLeft = 2,
	jumpingRight = 3,
	jumpingLeft = 4,
	fallingRight = 5,
	fallingLeft = 6,
	dyingFromRight = 7,
	dyingFromLeft = 8,
};

// CE COMPORTAMENT POATE AVEA O ENTITATE 2D CU O COMPONENTA DE COMPORTAMENT ATASATA

enum class EntityBehaviour
{
	notSet = -1,
	passive = 0,
	aggresive = 1,

	// VOR MAI URMA CANDVA
};

namespace ENTITY_BEHAVIOUR_CONSTANT
{
	const double AGGRESIVE_EPSILON_X = 90.0; // DISTANTA MAXIMA LA CARE VA INCERCA O ENTITATE 2D SA FIE FATA DE JUCATOR PE AXA OX (UNA AGRESIVA PE MOMENT)
	const double AGGRESIVE_EPSILON_Y = 350.0; // ANALOG PE OY
}

// STRUCTURA UNEI TEXTURI
struct TextureStructure;

// COMPONENT SYSTEM

const int MAX_ENTITIES = 2048; // NU FOLOSIM ASTA MOMENTAN
const int MAX_COMPONENTS = 64; // NUMARUL TOTAL DE COMPONENTE CE POT FI ATASATE SIMULTAN UNEI ENTITATI 2D

using ComponentTypeID = int;

using ComponentBitset = std::bitset<MAX_COMPONENTS>;
using ComponentList = std::array<Component*, MAX_COMPONENTS>;

inline ComponentTypeID InternalGetComponentTypeID()
{
	static ComponentTypeID lastID = 0;

	return lastID++;
}

template<typename T>
inline ComponentTypeID GetComponentTypeID()
{
	static const ComponentTypeID typeID = InternalGetComponentTypeID();

	return typeID;
}

// MAI JOS, TOATE DECLARILE NU SUNT IN ORDINEA DE MAI SUS, DIN CAUZA CA UNELE DEPIND DE ALTELE SI INTERVIN PROBLEME SI ALTFEL NU STIU SA LE REZOLV DECAT SCHIMBAND ORDINEA

// CLASA CHARACTER STORAGE

class CharacterStorage
{
public:

	static CharacterStorage* Get()
	{
		if (CharacterStorage::instance == nullptr)
		{
			CharacterStorage::instance = new CharacterStorage();
		}

		return CharacterStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: CHARACTER STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static CharacterStorage* instance;

	CharacterStorage() {};
};

CharacterStorage* CharacterStorage::instance = nullptr;

// CLASA TERRAIN STORAGE

class TerrainStorage
{
public:

	static TerrainStorage* Get()
	{
		if (TerrainStorage::instance == nullptr)
		{
			TerrainStorage::instance = new TerrainStorage();
		}

		return TerrainStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: TERRAIN STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static TerrainStorage* instance;

	TerrainStorage() {};
};

TerrainStorage* TerrainStorage::instance = nullptr;

// CLASA PROJECTILE STORAGE

class ProjectileStorage
{
public:

	static ProjectileStorage* Get()
	{
		if (ProjectileStorage::instance == nullptr)
		{
			ProjectileStorage::instance = new ProjectileStorage();
		}

		return ProjectileStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
		{
			if (this->entities[i] == entity)
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: PROJECTILE STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	void DestroyEntity(int index) // ASTA AR TREBUI APELATA DOAR DE MANAGERUL DE COLIZIUNE SI NICIODATA DE UTILIZATOR
	{
		delete this->entities[index];

		this->entities[index] = this->entities[this->entities.size() - 1];
		this->entities.pop_back();
	}

	std::vector<Entity*> entities;

private:

	static ProjectileStorage* instance;

	ProjectileStorage() {};
};

ProjectileStorage* ProjectileStorage::instance = nullptr;

// CLASA LANDSCAPE STORAGE

class LandscapeStorage
{
public:

	static LandscapeStorage* Get()
	{
		if (LandscapeStorage::instance == nullptr)
		{
			LandscapeStorage::instance = new LandscapeStorage();
		}

		return LandscapeStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: LANDSCAPE STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static LandscapeStorage* instance;

	LandscapeStorage() {};

};

LandscapeStorage* LandscapeStorage::instance = nullptr;

// CLASA HITBOX STORAGE

class HitboxStorage
{
public:

	static HitboxStorage* Get()
	{
		if (HitboxStorage::instance == nullptr)
		{
			HitboxStorage::instance = new HitboxStorage();
		}

		return HitboxStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: HITBOX STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static HitboxStorage* instance;

	HitboxStorage() {};

};

HitboxStorage* HitboxStorage::instance = nullptr;

// CLASA VELOCITY STORAGE

class SpeedStorage
{
public:

	static SpeedStorage* Get()
	{
		if (SpeedStorage::instance == nullptr)
		{
			SpeedStorage::instance = new SpeedStorage();
		}

		return SpeedStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: SPEED STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static SpeedStorage* instance;

	SpeedStorage() {};

};

SpeedStorage* SpeedStorage::instance = nullptr;

// CLASA ANIMATION STORAGE

class AnimationStorage
{
public:

	static AnimationStorage* Get()
	{
		if (AnimationStorage::instance == nullptr)
		{
			AnimationStorage::instance = new AnimationStorage();
		}

		return AnimationStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: ANIMATION STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static AnimationStorage* instance;

	AnimationStorage() {};

};

AnimationStorage* AnimationStorage::instance = nullptr;

// CLASA BEHAVIOUR STORAGE

class BehaviourStorage
{
public:

	static BehaviourStorage* Get()
	{
		if (BehaviourStorage::instance == nullptr)
		{
			BehaviourStorage::instance = new BehaviourStorage();
		}

		return BehaviourStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: BEHAVIOUR STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static BehaviourStorage* instance;

	BehaviourStorage() {};

};

BehaviourStorage* BehaviourStorage::instance = nullptr;

// CLASA INPUT STORAGE

class InputStorage
{
public:

	static InputStorage* Get()
	{
		if (InputStorage::instance == nullptr)
		{
			InputStorage::instance = new InputStorage();
		}

		return InputStorage::instance;
	}

	void AddEntity(Entity* entity)
	{
		this->entities.emplace_back(entity);
	}

	void RemoveEntity(Entity* entity)
	{
		for (int i = 0; i < this->entities.size(); i++)
		{
			if (this->entities[i] == entity) // DOAR INLATURA ENTITATEA DIN MANAGER, NU STERGE MEMORIA IN SINE, ASTA TREBUIE FACUTA MANUAL DE UTILIZATOR
			{
				this->entities[i] = this->entities[this->entities.size() - 1];
				this->entities.pop_back();

				return;
			}
		}

		std::cout << "WARNING :: INPUT STORAGE :: COULD NOT REMOVE ENTITY SINCE IT WAS NOT THERE\n";
	}

	std::vector<Entity*> entities;

private:

	static InputStorage* instance;

	InputStorage() {};

};

InputStorage* InputStorage::instance = nullptr;

// CLASA WINDOW MANAGER

class WindowManager
{
public:

	static WindowManager* Get()
	{
		if (WindowManager::instance == nullptr)
		{
			WindowManager::instance = new WindowManager();
		}

		return WindowManager::instance;
	}

	void CreateWindow(int windowWidth, int windowHeight, std::string windowTitle)
	{
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;
		this->windowTitle = windowTitle;

		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->window = glfwCreateWindow(this->windowWidth, this->windowHeight, this->windowTitle.c_str(), NULL, NULL);
		//glfwGetPrimaryMonitor();

		glfwMakeContextCurrent(this->window);

		glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

		glewInit();

		glfwSwapInterval(1);
	}

	void UpdateWindow()
	{
		glfwSwapBuffers(this->window);

		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
	}

	void DestroyWindow()
	{
		glfwSetWindowShouldClose(this->window, true);

		glfwDestroyWindow(this->window);

		this->window = nullptr;
	}

	void SetWindowShouldClose(bool state)
	{
		glfwSetWindowShouldClose(this->window, state);
	}

	void SetClearColor(double red, double green, double blue)
	{
		glClearColor(red, green, blue, 1.0);
	}

	void SetClearColor(double red, double green, double blue, double alpha)
	{
		glClearColor(red, green, blue, alpha);
	}

	bool ShouldWindowClose()
	{
		return glfwWindowShouldClose(this->window);
	}

	GLFWwindow* GetWindow()
	{
		return this->window;
	}

	int GetWindowWidth()
	{
		return this->windowWidth;
	}

	int GetWindowHeight()
	{
		return this->windowHeight;
	}

private:

	static WindowManager* instance;

	int windowWidth = 1024;
	int windowHeight = 768;

	std::string windowTitle;

	GLFWwindow* window = nullptr;

	WindowManager() {};
};

WindowManager* WindowManager::instance = nullptr;

// STRUCTURA TEXTURA

struct TextureStructure
{
	unsigned int ID = 0;

	int width = 0;
	int height = 0;

	int nrChannels = 0;
};

// CLASA ASSET MANAGER

class AssetManager
{
public:

	static AssetManager* Get()
	{
		if (AssetManager::instance == nullptr)
		{
			AssetManager::instance = new AssetManager();
		}

		return AssetManager::instance;
	}

	void AddTexture(std::string name, std::string address)
	{
		TextureStructure texture;

		glGenTextures(1, &texture.ID);
		glBindTexture(GL_TEXTURE_2D, texture.ID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		unsigned char* data = SOIL_load_image(address.c_str(), &texture.width, &texture.height, &texture.nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width, texture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			this->textures.insert({ name, texture });
		}
		else
		{
			std::cout << "ERROR :: ASSET MANAGER :: ADDTEXTURE :: COULD NOT FIND THE TEXTURED NAMED \"" << name << "\" AT THE ADDRESS \"" << address << "\"\n";
		}

		SOIL_free_image_data(data);
	}

	unsigned int GetTextureID(std::string name)
	{
		if (this->textures.find(name) == this->textures.end())
		{
			std::cout << "ERROR :: ASSET MANAGER :: GETTEXTUREID :: COULD NOT FIND THE TEXTURE NAMED \"" << name << "\". RETURNING ERROR TEXTURE ID INSTEAD...\n";

			return this->errorTexture.ID;
		}

		return this->textures[name].ID;

	}

	unsigned int GetErrorTextureID()
	{
		return this->errorTexture.ID;
	}

private:

	static AssetManager* instance;

	TextureStructure errorTexture;
	std::unordered_map<std::string, TextureStructure> textures;

	std::string errorTextureAddress = "GameEngine2D/Textures/ErrorTexture/ErrorTexture.png";

	AssetManager()
	{
		glGenTextures(1, &this->errorTexture.ID);
		glBindTexture(GL_TEXTURE_2D, this->errorTexture.ID);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		unsigned char* data = SOIL_load_image(this->errorTextureAddress.c_str(), &this->errorTexture.width, &this->errorTexture.height, &this->errorTexture.nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->errorTexture.width, this->errorTexture.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "ERROR :: ASSET MANAGER :: COULD NOT FIND THE ERROR TEXTURE AT THE ADDRESS \"" << this->errorTextureAddress << "\"\n";
		}

		SOIL_free_image_data(data);
	};
};

AssetManager* AssetManager::instance = nullptr;

// CLASA RENDERER

class Renderer
{
public:

	Renderer(std::string vertexShaderAddress, std::string fragmentShaderAddress)
	{

		std::ifstream fileInput;
		std::string line;

		fileInput.open(vertexShaderAddress);

		if (fileInput)
		{
			while (!fileInput.eof())
			{
				getline(fileInput, line);

				this->vertexShaderCode += line;
				this->vertexShaderCode += "\n";
			}

			this->vertexShaderCode += "\0";
		}
		else
		{
			std::cout << "ERROR :: RENDERER :: COULD NOT FIND ANY FILE AT THE ADDRESS \"" << vertexShaderAddress << "\" WHICH CONTAINS THE VERTEX SHADER CODE\n";
		}

		fileInput.close();

		fileInput.open(fragmentShaderAddress);

		if (fileInput)
		{
			while (!fileInput.eof())
			{
				getline(fileInput, line);

				this->fragmentShaderCode += line;
				this->fragmentShaderCode += "\n";
			}

			this->fragmentShaderCode += "\0";
		}
		else
		{
			std::cout << "ERROR :: RENDERER :: COULD NOT FIND ANY FILE AT THE ADDRESS \"" << fragmentShaderAddress << "\" WHICH CONTAINS THE FRAGMENT SHADER CODE\n";
		}

		fileInput.close();

		const char* vertexCstr = (this->vertexShaderCode).c_str();
		const char* fragmentCstr = (this->fragmentShaderCode).c_str();

		this->vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		this->fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(this->vertexShaderID, 1, &vertexCstr, 0);
		glShaderSource(this->fragmentShaderID, 1, &fragmentCstr, 0);

		glCompileShader(this->vertexShaderID);
		glCompileShader(this->fragmentShaderID);

		this->programID = glCreateProgram();
		glAttachShader(this->programID, this->vertexShaderID);
		glAttachShader(this->programID, this->fragmentShaderID);

		glLinkProgram(this->programID);

		//glValidateProgram(this->programID);

		glUseProgram(this->programID);

		glGenVertexArrays(1, &this->VAOID);
		glGenBuffers(1, &this->VBOID);

		glBindVertexArray(this->VAOID);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBOID);

		glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, 4 * sizeof(double), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE, 4 * sizeof(double), (void*)(2 * sizeof(double)));
		glEnableVertexAttribArray(1);

		this->ortho = glm::ortho(0.0, 1.0 * WindowManager::Get()->GetWindowWidth(), 0.0, 1.0 * WindowManager::Get()->GetWindowHeight());
		this->orthoPath = glGetUniformLocation(this->programID, "ortho");
		glUniformMatrix4fv(this->orthoPath, 1, GL_FALSE, glm::value_ptr(this->ortho));

		this->texturePath = glGetUniformLocation(this->programID, "texture0");
		glUniform1i(this->texturePath, 0);

		glActiveTexture(GL_TEXTURE0);

		glUseProgram(0);
	}

	~Renderer()
	{
		glDeleteBuffers(1, &this->VBOID);
		glDeleteVertexArrays(1, &this->VAOID);

		glDeleteShader(this->vertexShaderID);
		glDeleteShader(this->fragmentShaderID);

		glDeleteProgram(this->programID);
	}

	inline void StartUsing()
	{
		glUseProgram(this->programID);
	}

	inline void StopUsing()
	{
		glUseProgram(0);
	}

	unsigned int GetVAOID()
	{
		return this->VAOID;
	}

	unsigned int GetVBOID()
	{
		return this->VBOID;
	}

private:

	int programID;

	int vertexShaderID;
	int fragmentShaderID;

	std::string vertexShaderCode;
	std::string fragmentShaderCode;

	int orthoPath;
	glm::mat4 ortho;

	int texturePath;

	unsigned int VAOID;
	unsigned int VBOID;
};

// CLASA CAMERA

class Camera
{
public:

	static Camera* Get()
	{
		if (Camera::instance == nullptr)
		{
			Camera::instance = new Camera();
		}

		return Camera::instance;
	}

	void FollowEntity(Entity* entity)
	{
		this->followedEntity = entity;
	}

	void UnfollowEntity()
	{
		this->followedEntity = nullptr;
	}

	Entity* GetFollowedEntity()
	{
		return this->followedEntity;
	}

private:

	static Camera* instance;

	Entity* followedEntity;

	Camera()
	{
		this->followedEntity = nullptr;
	}
};

Camera* Camera::instance = nullptr;

// CLASA ENTITY

class Entity
{
public:

	Entity(EntityType entityType) : entityType(entityType)
	{
		for (int i = 0; i < MAX_COMPONENTS; i++)
		{
			this->componentBitset[i] = false;
			this->componentList[i] = nullptr;
		}

		if (this->entityType == EntityType::character)
		{
			CharacterStorage::Get()->AddEntity(this);
		}
		else if (this->entityType == EntityType::terrain)
		{
			TerrainStorage::Get()->AddEntity(this);
		}
		else if (this->entityType == EntityType::projectile)
		{
			ProjectileStorage::Get()->AddEntity(this);
		}
	}

	virtual ~Entity()
	{
		for (int i = 0; i < MAX_COMPONENTS; i++)
		{
			if (this->componentBitset[i])
			{
				delete this->componentList[i];
				this->componentBitset[i] = false;

				if (i == GetComponentTypeID<Hitbox>())
				{
					HitboxStorage::Get()->RemoveEntity(this);
				}
				else if (i == GetComponentTypeID<Speed>())
				{
					SpeedStorage::Get()->RemoveEntity(this);
				}
				else if (i == GetComponentTypeID<Animation>())
				{
					AnimationStorage::Get()->RemoveEntity(this);
				}
				else if (i == GetComponentTypeID<Behaviour>())
				{
					BehaviourStorage::Get()->RemoveEntity(this);
				}
				else if (i == GetComponentTypeID<Input>())
				{
					InputStorage::Get()->RemoveEntity(this);
				}
			}
		}

		if (entityType == EntityType::character)
		{
			CharacterStorage::Get()->RemoveEntity(this);
		}
		else if (entityType == EntityType::terrain)
		{
			TerrainStorage::Get()->RemoveEntity(this);
		}
		else if (entityType == EntityType::projectile)
		{
			ProjectileStorage::Get()->RemoveEntity(this);
		}
		else if (entityType == EntityType::landscape)
		{
			LandscapeStorage::Get()->RemoveEntity(this);
		}
	}

	template<typename T>
	inline void AddComponent(T* component)
	{
		this->componentBitset[GetComponentTypeID<T>()] = true;
		this->componentList[GetComponentTypeID<T>()] = component;

		component->entity = this;

		if (GetComponentTypeID<T>() == GetComponentTypeID<Hitbox>())
		{
			HitboxStorage::Get()->AddEntity(this);
		}
		else if (GetComponentTypeID<T>() == GetComponentTypeID<Speed>())
		{
			SpeedStorage::Get()->AddEntity(this);
		}
		else if (GetComponentTypeID<T>() == GetComponentTypeID<Animation>())
		{
			AnimationStorage::Get()->AddEntity(this);
		}
		else if (GetComponentTypeID<T>() == GetComponentTypeID<Behaviour>())
		{
			BehaviourStorage::Get()->AddEntity(this);
		}
		else if (GetComponentTypeID<T>() == GetComponentTypeID<Input>())
		{
			InputStorage::Get()->AddEntity(this);
		}
	}

	template<typename T>
	inline void DeleteComponent()
	{
		if (this->componentBitset[GetComponentTypeID<T>()])
		{
			delete this->componentList[GetComponentTypeID<T>()];

			this->componentBitset[GetComponentTypeID<T>()] = false;
			this->componentList[GetComponentTypeID<T>()] = nullptr;

			if (GetComponentTypeID<T>() == GetComponentTypeID<Hitbox>())
			{
				HitboxStorage::Get()->RemoveEntity(this);
			}
			else if (GetComponentTypeID<T>() == GetComponentTypeID<Speed>())
			{
				SpeedStorage::Get()->RemoveEntity(this);
			}
			else if (GetComponentTypeID<T>() == GetComponentTypeID<Animation>())
			{
				AnimationStorage::Get()->RemoveEntity(this);
			}
			else if (GetComponentTypeID<T>() == GetComponentTypeID<Behaviour>())
			{
				BehaviourStorage::Get()->RemoveEntity(this);
			}
			else if (GetComponentTypeID<T>() == GetComponentTypeID<Input>())
			{
				InputStorage::Get()->RemoveEntity(this);
			}
		}
		else
		{
			std::cout << "WARNING :: ENTITY :: DELETECOMPONENT :: COULD NOT DELETE A COMPONENT WHICH DID NOT EXIST IN THE FIRST PLACE\n";
		}
	}

	template<typename T>
	inline T* GetComponent() const
	{
		if (!this->componentBitset[GetComponentTypeID<T>()])
		{
			std::cout << "WARNING :: ENTITY :: GETCOMPONENT :: UNCREATED COMPONENT WAS DEMANDED. RETURNING NULL POINTER...\n";

			return nullptr;
		}

		return static_cast<T*>(this->componentList[GetComponentTypeID<T>()]);
	}

	template<typename T>
	inline bool HasComponent() const
	{
		return this->componentBitset[GetComponentTypeID<T>()];
	}

	EntityType GetEntityType()
	{
		return this->entityType;
	}

private:

	EntityType entityType;

	ComponentBitset componentBitset;
	ComponentList componentList;
};

// CLASA COMPONENT

class Component
{
public:

	Component() {};
	virtual ~Component() {};

	Entity* entity = nullptr;

private:

};

// CLASELE COMPONENTELOR CE SE MOSTENESC DIN COMPONENTA DE BAZA, VIRTUALA

class Position : public Component
{
public:

	Position(double x, double y) : x(x), y(y) {};

	double x;
	double y;

private:

};

class Hitbox : public Component
{
public:

	Hitbox(double width, double height) : width(width), height(height)
	{
		this->collidedDownward = false;
	}

	double width;
	double height;

	bool collidedDownward;

private:

};

class Texture : public Component
{
public:

	Texture()
	{
		this->currentTextureID = 0;
	}

	unsigned int currentTextureID;

private:

};

class TextureBox : public Component
{
public:

	TextureBox(double width, double height) : width(width), height(height) {};

	double width;
	double height;

private:

};

class Render : public Component
{
public:

	Render() {};

	void Draw(Renderer* renderer)
	{
		bool isOK = true;

		if (!this->entity->HasComponent<Position>())
		{
			std::cout << "ERROR :: RENDER COMPONENT :: DRAW :: THERE IS NO POSITION COMPONENT FOR ENTITY. RETURNING WITHOUT DRAWING...\n";

			isOK = false;
		}
		if (!this->entity->HasComponent<TextureBox>())
		{
			std::cout << "ERROR :: RENDER COMPONENT :: DRAW :: THERE IS NO TEXTUREBOX COMPONENT FOR ENTITY. RETURNING WITHOUT DRAWING...\n";

			isOK = false;
		}
		if (!this->entity->HasComponent<Texture>())
		{
			std::cout << "ERROR :: RENDER COMPONENT :: DRAW :: THERE IS NO TEXTURE COMPONENT FOR ENTITY. RETURNING WITHOUT DRAWING...\n";

			isOK = false;
		}

		if (this->entity->GetComponent<Texture>()->currentTextureID == 0)
		{
			std::cout << "WARNING :: RENDER COMPONENT :: DRAW :: THERE IS NO TEXTURE TO USE FOR DRAWING. SELECTING THE ERROR TEXTURE INSTEAD AND ATTEMPTING DRAWING...\n";

			entity->GetComponent<Texture>()->currentTextureID = AssetManager::Get()->GetErrorTextureID();
		}

		if (!isOK) return;

		data.clear();

		// TEXTURILE AU ORIGINEA O(0, 0) IN COLTUL DE SUS DIN STANGA

		/*
		6-------3/4
		|        |
		|        |
		|        |
		1/5------2
		*/

		if (Camera::Get()->GetFollowedEntity() == nullptr)
		{
			data.push_back(entity->GetComponent<Position>()->x - entity->GetComponent<TextureBox>()->width / 2.0);
			data.push_back(entity->GetComponent<Position>()->y - entity->GetComponent<TextureBox>()->height / 2.0);

			data.push_back(0.0);
			data.push_back(1.0);

			data.push_back(entity->GetComponent<Position>()->x + entity->GetComponent<TextureBox>()->width / 2.0);
			data.push_back(entity->GetComponent<Position>()->y - entity->GetComponent<TextureBox>()->height / 2.0);

			data.push_back(1.0);
			data.push_back(1.0);

			data.push_back(entity->GetComponent<Position>()->x + entity->GetComponent<TextureBox>()->width / 2.0);
			data.push_back(entity->GetComponent<Position>()->y + entity->GetComponent<TextureBox>()->height / 2.0);

			data.push_back(1.0);
			data.push_back(0.0);

			data.push_back(entity->GetComponent<Position>()->x + entity->GetComponent<TextureBox>()->width / 2.0);
			data.push_back(entity->GetComponent<Position>()->y + entity->GetComponent<TextureBox>()->height / 2.0);

			data.push_back(1.0);
			data.push_back(0.0);

			data.push_back(entity->GetComponent<Position>()->x - entity->GetComponent<TextureBox>()->width / 2.0);
			data.push_back(entity->GetComponent<Position>()->y - entity->GetComponent<TextureBox>()->height / 2.0);

			data.push_back(0.0);
			data.push_back(1.0);

			data.push_back(entity->GetComponent<Position>()->x - entity->GetComponent<TextureBox>()->width / 2.0);
			data.push_back(entity->GetComponent<Position>()->y + entity->GetComponent<TextureBox>()->height / 2.0);

			data.push_back(0.0);
			data.push_back(0.0);

			renderer->StartUsing();

			glBindVertexArray(renderer->GetVAOID());
			glBindBuffer(GL_ARRAY_BUFFER, renderer->GetVBOID());

			glBindTexture(GL_TEXTURE_2D, this->entity->GetComponent<Texture>()->currentTextureID);

			glBufferData(GL_ARRAY_BUFFER, sizeof(double) * data.size(), &data[0], GL_DYNAMIC_DRAW);

			glDrawArrays(GL_TRIANGLES, 0, data.size() / 4);
		}
		else
		{
			if (Camera::Get()->GetFollowedEntity()->HasComponent<Position>())
			{
				data.push_back(entity->GetComponent<Position>()->x - entity->GetComponent<TextureBox>()->width / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->x + WindowManager::Get()->GetWindowWidth() / 2.0);
				data.push_back(entity->GetComponent<Position>()->y - entity->GetComponent<TextureBox>()->height / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->y + WindowManager::Get()->GetWindowHeight() / 2.0);

				data.push_back(0.0);
				data.push_back(1.0);

				data.push_back(entity->GetComponent<Position>()->x + entity->GetComponent<TextureBox>()->width / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->x + WindowManager::Get()->GetWindowWidth() / 2.0);
				data.push_back(entity->GetComponent<Position>()->y - entity->GetComponent<TextureBox>()->height / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->y + WindowManager::Get()->GetWindowHeight() / 2.0);

				data.push_back(1.0);
				data.push_back(1.0);

				data.push_back(entity->GetComponent<Position>()->x + entity->GetComponent<TextureBox>()->width / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->x + WindowManager::Get()->GetWindowWidth() / 2.0);
				data.push_back(entity->GetComponent<Position>()->y + entity->GetComponent<TextureBox>()->height / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->y + WindowManager::Get()->GetWindowHeight() / 2.0);

				data.push_back(1.0);
				data.push_back(0.0);

				data.push_back(entity->GetComponent<Position>()->x + entity->GetComponent<TextureBox>()->width / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->x + WindowManager::Get()->GetWindowWidth() / 2.0);
				data.push_back(entity->GetComponent<Position>()->y + entity->GetComponent<TextureBox>()->height / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->y + WindowManager::Get()->GetWindowHeight() / 2.0);

				data.push_back(1.0);
				data.push_back(0.0);

				data.push_back(entity->GetComponent<Position>()->x - entity->GetComponent<TextureBox>()->width / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->x + WindowManager::Get()->GetWindowWidth() / 2.0);
				data.push_back(entity->GetComponent<Position>()->y - entity->GetComponent<TextureBox>()->height / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->y + WindowManager::Get()->GetWindowHeight() / 2.0);

				data.push_back(0.0);
				data.push_back(1.0);

				data.push_back(entity->GetComponent<Position>()->x - entity->GetComponent<TextureBox>()->width / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->x + WindowManager::Get()->GetWindowWidth() / 2.0);
				data.push_back(entity->GetComponent<Position>()->y + entity->GetComponent<TextureBox>()->height / 2.0 - Camera::Get()->GetFollowedEntity()->GetComponent<Position>()->y + WindowManager::Get()->GetWindowHeight() / 2.0);

				data.push_back(0.0);
				data.push_back(0.0);

				renderer->StartUsing();

				glBindVertexArray(renderer->GetVAOID());
				glBindBuffer(GL_ARRAY_BUFFER, renderer->GetVBOID());

				glBindTexture(GL_TEXTURE_2D, this->entity->GetComponent<Texture>()->currentTextureID);

				glBufferData(GL_ARRAY_BUFFER, sizeof(double) * data.size(), &data[0], GL_DYNAMIC_DRAW);

				glDrawArrays(GL_TRIANGLES, 0, data.size() / 4);
			}
			else
			{
				std::cout << "ERROR :: RENDER COMPONENT :: DRAW :: THERE IS NO POSITION COMPONENT FOR THE FOLLOWED ENTITY. RETURNING WITHOUT DRAWING...\n";
			}
		}
	}

private:

	std::vector<double> data;

};

class Speed : public Component
{
public:

	Speed(double speedX = 0.0, double speedY = 0.0) : speedX(speedX), speedY(speedY) {};

	double speedX;
	double speedY;

private:

};

class Acceleration : public Component
{
public:

	Acceleration(double accelerationX = 0.0, double accelerationY = 0.0) : accelerationX(accelerationX), accelerationY(accelerationY) {};

	double accelerationX;
	double accelerationY;

private:

};

class Gravity : public Component
{
public:

	Gravity(double value = 10.0) : value(value) {};

	double value;

private:

};

class Animation : public Component
{
public:

	Animation(double frameTime = 0.1) : frameTime(frameTime)
	{
		this->currentEntityAnimation = EntityAnimation::notSet;

		this->lastEntityAnimation = EntityAnimation::notSet;

		this->timeWhenCurrentAnimationStarted = 0.0;
	}

	std::vector<unsigned int> animations[MAX_ANIMATIONS_ENTITY];

	EntityAnimation currentEntityAnimation;
	EntityAnimation lastEntityAnimation;

	double frameTime;
	double timeWhenCurrentAnimationStarted;

private:

};

class MovementSpeed : public Component
{
public:

	MovementSpeed(double speedX = 0.0, double speedY = 0.0) : speedX(speedX), speedY(speedY)
	{
		this->wentRight = false;
		this->wentLeft = false;
	}

	double speedX;
	double speedY;

	bool wentRight;
	bool wentLeft;

private:

};

class Behaviour : public Component
{
public:

	Behaviour(EntityBehaviour state, Entity* target = nullptr) : state(state), target(target) {};

	EntityBehaviour state;

	Entity* target;

private:

};

class Input : public Component
{
public:

	Input() {};

private:

};

// CLASA TIME MANAGER

class TimeManager
{
public:

	static TimeManager* Get()
	{
		if (TimeManager::instance == nullptr)
		{
			TimeManager::instance = new TimeManager();
		}

		return TimeManager::instance;
	}

	void UpdateDeltaTime()
	{
		this->previousTime = this->currentTime;
		this->currentTime = glfwGetTime();
		this->deltaTime = this->currentTime - this->previousTime;
	}

	double GetDeltaTime()
	{
		return this->deltaTime;
	}

	double GetCurrentTime()
	{
		return this->currentTime;
	}

private:

	double deltaTime = 0.0;

	double currentTime = 0.0;
	double previousTime = 0.0;

	static TimeManager* instance;

	TimeManager()
	{
		glfwSetTime(0.0);
	}
};

TimeManager* TimeManager::instance = nullptr;

// CLASA INPUT MANAGER

class InputManager
{
public:

	static InputManager* Get()
	{
		if (InputManager::instance == nullptr)
		{
			InputManager::instance = new InputManager();
		}

		return InputManager::instance;
	}

	void ListenForInput()
	{
		if (glfwGetKey(WindowManager::Get()->GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			this->gameEngineShouldStop = true;
		}

		if (InputStorage::Get()->entities.size() == 0)
		{
			std::cout << "WARNING :: INPUT MANAGER :: LISTENFORINPUT :: THERE IS NO PLAYER ENTITY TO APPLY INPUT TO\n";

			return;
		}

		for (int i = 0; i < InputStorage::Get()->entities.size(); i++)
		{
			bool isOK = true;

			if (!InputStorage::Get()->entities[i]->HasComponent<Speed>())
			{
				std::cout << "WARNING :: INPUT MANAGER :: LISTENFORINPUT :: THERE IS AN ENTITY WITH INPUT COMPONENT BUT WITHOUT SPEED COMPONENT. CAN NOT APPLY INPUT\n";

				isOK = false;
			}
			if (!InputStorage::Get()->entities[i]->HasComponent<MovementSpeed>())
			{
				std::cout << "WARNING :: INPUT MANAGER :: LISTENFORINPUT :: THERE IS AN ENTITY WITH INPUT COMPONENT BUT WITHOUT MOVEMENTSPEED COMPONENT. CAN NOT APPLY INPUT\n";

				isOK = false;
			}

			if (!isOK) continue;

			if (glfwGetKey(WindowManager::Get()->GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
			{
				if (!InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentRight)
				{
					InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentRight = true;

					InputStorage::Get()->entities[i]->GetComponent<Speed>()->speedX += InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;
				}
			}
			else if (InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentRight)
			{
				InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentRight = false;

				InputStorage::Get()->entities[i]->GetComponent<Speed>()->speedX -= InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;
			}

			if (glfwGetKey(WindowManager::Get()->GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
			{
				if (!InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentLeft)
				{
					InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentLeft = true;

					InputStorage::Get()->entities[i]->GetComponent<Speed>()->speedX -= InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;
				}
			}
			else if (InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentLeft)
			{
				InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentLeft = false;

				InputStorage::Get()->entities[i]->GetComponent<Speed>()->speedX += InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;
			}

			if (glfwGetKey(WindowManager::Get()->GetWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
			{
				if (InputStorage::Get()->entities[i]->HasComponent<Hitbox>())
				{
					if (InputStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward)
					{
						InputStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward = false;

						InputStorage::Get()->entities[i]->GetComponent<Speed>()->speedY += InputStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedY;
					}
				}
				else
				{
					std::cout << "WARNING :: INPUT MANAGER :: LISTENFORINPUT :: THERE IS AN ENTITY WHICH CAN NOT JUMP SINCE IT DOES NOT POSSESS A HITBOX. CAN NOT APPLY JUMPING\n";
				}
			}
		}
	}

	bool ShouldGameEngineStop()
	{
		return this->gameEngineShouldStop;
	}

private:

	static InputManager* instance;

	bool gameEngineShouldStop;

	InputManager()
	{
		this->gameEngineShouldStop = false;
	}
};

InputManager* InputManager::instance = nullptr;

// CLASA MOVEMENT MANAGER

class MovementManager
{
public:

	static MovementManager* Get()
	{
		if (MovementManager::instance == nullptr)
		{
			MovementManager::instance = new MovementManager();
		}

		return MovementManager::instance;
	}

	void UpdateMovements()
	{
		for (int i = 0; i < SpeedStorage::Get()->entities.size(); i++)
		{
			if (SpeedStorage::Get()->entities[i]->HasComponent<Gravity>())
			{
				SpeedStorage::Get()->entities[i]->GetComponent<Speed>()->speedY += SpeedStorage::Get()->entities[i]->GetComponent<Gravity>()->value * TimeManager::Get()->GetDeltaTime();
			}
			if (SpeedStorage::Get()->entities[i]->HasComponent<Acceleration>())
			{
				SpeedStorage::Get()->entities[i]->GetComponent<Speed>()->speedX += SpeedStorage::Get()->entities[i]->GetComponent<Acceleration>()->accelerationX * TimeManager::Get()->GetDeltaTime();
				SpeedStorage::Get()->entities[i]->GetComponent<Speed>()->speedY += SpeedStorage::Get()->entities[i]->GetComponent<Acceleration>()->accelerationY * TimeManager::Get()->GetDeltaTime();
			}

			if (SpeedStorage::Get()->entities[i]->HasComponent<Position>())
			{

				SpeedStorage::Get()->entities[i]->GetComponent<Position>()->x += SpeedStorage::Get()->entities[i]->GetComponent<Speed>()->speedX * TimeManager::Get()->GetDeltaTime();
				SpeedStorage::Get()->entities[i]->GetComponent<Position>()->y += SpeedStorage::Get()->entities[i]->GetComponent<Speed>()->speedY * TimeManager::Get()->GetDeltaTime();
			}
		}
	}

private:

	static MovementManager* instance;

	MovementManager() {};

};

MovementManager* MovementManager::instance = nullptr;

// CLASA COLLISION MANAGER

class CollisionManager
{
public:

	static CollisionManager* Get()
	{
		if (CollisionManager::instance == nullptr)
		{
			CollisionManager::instance = new CollisionManager();
		}

		return CollisionManager::instance;
	}

	void UpdateCollisions()
	{
		for (int i = 0; i < CharacterStorage::Get()->entities.size(); i++)
		{

			if (!CharacterStorage::Get()->entities[i]->HasComponent<Position>() || !CharacterStorage::Get()->entities[i]->HasComponent<Hitbox>()) continue;

			for (int j = 0; j < ProjectileStorage::Get()->entities.size(); j++)
			{
				if (!ProjectileStorage::Get()->entities[j]->HasComponent<Position>() || !ProjectileStorage::Get()->entities[j]->HasComponent<Hitbox>()) continue;

				if (std::max(CharacterStorage::Get()->entities[i]->GetComponent<Position>()->x - CharacterStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->x - ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0) <=
					std::min(CharacterStorage::Get()->entities[i]->GetComponent<Position>()->x + CharacterStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->x + ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0) &&
					std::max(CharacterStorage::Get()->entities[i]->GetComponent<Position>()->y - CharacterStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->y - ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0) <=
					std::min(CharacterStorage::Get()->entities[i]->GetComponent<Position>()->y + CharacterStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->y + ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0))
				{
					ProjectileStorage::Get()->DestroyEntity(j);
					j--;
				}
			}
		}

		for (int i = 0; i < CharacterStorage::Get()->entities.size(); i++)
		{
			if (CharacterStorage::Get()->entities[i]->HasComponent<Hitbox>())
			{
				CharacterStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward = false;
			}
		}

		for (int i = 0; i < TerrainStorage::Get()->entities.size(); i++)
		{
			if (!TerrainStorage::Get()->entities[i]->HasComponent<Position>() || !TerrainStorage::Get()->entities[i]->HasComponent<Hitbox>()) continue;

			for (int j = 0; j < CharacterStorage::Get()->entities.size(); j++)
			{
				if (!CharacterStorage::Get()->entities[j]->HasComponent<Position>() || !CharacterStorage::Get()->entities[j]->HasComponent<Hitbox>()) continue;

				if (std::max(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->x - TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0, CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x - CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0) <=
					std::min(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->x + TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0, CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0) &&
					std::max(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y - TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0, CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y - CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0) <=
					std::min(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y + TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0, CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0))
				{
					// COLIZIUNE CU REZOLVARE PE AXA OX
					if (TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0 + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0 - std::abs(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->x - CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x) < TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0 + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0 - std::abs(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y - CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y))
					{
						if (TerrainStorage::Get()->entities[i]->GetComponent<Position>()->x < CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x)
						{
							CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x += TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0 + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0 - (CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x - TerrainStorage::Get()->entities[i] ->GetComponent<Position>()->x);

							if (CharacterStorage::Get()->entities[j]->HasComponent<MovementSpeed>())
							{
								if (CharacterStorage::Get()->entities[j]->GetComponent<MovementSpeed>()->wentLeft)
								{
									CharacterStorage::Get()->entities[j]->GetComponent<MovementSpeed>()->wentLeft = false;
								}
							}

							if (CharacterStorage::Get()->entities[j]->HasComponent<Speed>())
							{
								if (CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedX < 0.0)
								{
									CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedX = 0.0;
								}
							}
						}
						else
						{
							CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x -= TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0 + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0 - (TerrainStorage::Get()->entities[i]->GetComponent<Position>()->x - CharacterStorage::Get()->entities[j]->GetComponent<Position>()->x);

							if (CharacterStorage::Get()->entities[j]->HasComponent<MovementSpeed>())
							{
								if (CharacterStorage::Get()->entities[j]->GetComponent<MovementSpeed>()->wentRight)
								{
									CharacterStorage::Get()->entities[j]->GetComponent<MovementSpeed>()->wentRight = false;
								}
							}

							if (CharacterStorage::Get()->entities[j]->HasComponent<Speed>())
							{
								if (CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedX > 0.0)
								{
									CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedX = 0.0;
								}
							}
						}
					}
					// PE AXA OY
					else
					{
						if (TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y < CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y)
						{
							CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y += TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0 + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0 - (CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y - TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y);

							CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->collidedDownward = true;

							if (CharacterStorage::Get()->entities[j]->HasComponent<Speed>())
							{
								if (CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedY < 0.0)
								{
									CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedY = 0.0;
								}
							}
						}
						else
						{
							CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y -= TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0 + CharacterStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0 - (TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y - CharacterStorage::Get()->entities[j]->GetComponent<Position>()->y);

							if (CharacterStorage::Get()->entities[j]->HasComponent<Speed>())
							{
								if (CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedY > 0.0)
								{
									CharacterStorage::Get()->entities[j]->GetComponent<Speed>()->speedY = 0.0;
								}
							}
						}
					}

				}
			}

			for (int j = 0; j < ProjectileStorage::Get()->entities.size(); j++)
			{
				if (!ProjectileStorage::Get()->entities[j]->HasComponent<Position>() || !ProjectileStorage::Get()->entities[j]->HasComponent<Hitbox>()) continue;

				if (std::max(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->x - TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->x - ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0) <=
					std::min(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->x + TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->width / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->x + ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->width / 2.0) &&
					std::max(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y - TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->y - ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0) <=
					std::min(TerrainStorage::Get()->entities[i]->GetComponent<Position>()->y + TerrainStorage::Get()->entities[i]->GetComponent<Hitbox>()->height / 2.0, ProjectileStorage::Get()->entities[j]->GetComponent<Position>()->y + ProjectileStorage::Get()->entities[j]->GetComponent<Hitbox>()->height / 2.0))
				{
					ProjectileStorage::Get()->DestroyEntity(j);
					j--;
				}
			}
		}
	}

private:

	static CollisionManager* instance;

	CollisionManager() {};

};

CollisionManager* CollisionManager::instance = nullptr;

// CLASA ANIMATION MANAGER

class AnimationManager
{
public:

	static AnimationManager* Get()
	{
		if (AnimationManager::instance == nullptr)
		{
			AnimationManager::instance = new AnimationManager();
		}

		return AnimationManager::instance;
	}

	void UpdateAnimations()
	{
		for (int i = 0; i < AnimationStorage::Get()->entities.size(); i++)
		{
			bool isOK = true;

			if (!AnimationStorage::Get()->entities[i]->HasComponent<Speed>())
			{
				std::cout << "ERROR :: ANIMATION MANAGER :: UPDATEANIMATIONS :: AN ENTITY DOES NOT POSSESS A SPEED COMPONENT. CAN NOT APPLY ANIMATIONS\n";

				isOK = false;
			}
			if (!AnimationStorage::Get()->entities[i]->HasComponent<Texture>())
			{
				std::cout << "ERROR :: ANIMATION MANAGER :: UPDATEANIMATIONS :: AN ENTITY DOES NOT POSSESS A TEXTURE COMPONENT, CAN NOT APPLY ANIMATIONS\n";

				isOK = false;
			}

			if (!isOK) continue;

			AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->lastEntityAnimation = AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation;

			if (AnimationStorage::Get()->entities[i]->GetComponent<Speed>()->speedY == 0.0)
			{
				if (AnimationStorage::Get()->entities[i]->GetComponent<Speed>()->speedX == 0.0)
				{
					AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation = EntityAnimation::standing;
				}
				else if (AnimationStorage::Get()->entities[i]->GetComponent<Speed>()->speedX > 0.0)
				{
					AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation = EntityAnimation::walkingRight;
				}
				else
				{
					AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation = EntityAnimation::walkingLeft;
				}
			}
			else if (AnimationStorage::Get()->entities[i]->GetComponent<Speed>()->speedY > 0.0)
			{
				if (AnimationStorage::Get()->entities[i]->GetComponent<Speed>()->speedX >= 0.0)
				{
					AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation = EntityAnimation::jumpingRight;
				}
				else
				{
					AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation = EntityAnimation::jumpingLeft;
				}
			}
			else
			{
				if (AnimationStorage::Get()->entities[i]->GetComponent<Speed>()->speedX >= 0.0)
				{
					AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation = EntityAnimation::fallingRight;
				}
				else
				{
					AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation = EntityAnimation::fallingLeft;
				}
			}

			if (AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation != AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->lastEntityAnimation)
			{
				AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->timeWhenCurrentAnimationStarted = TimeManager::Get()->GetCurrentTime();
			}

			AnimationStorage::Get()->entities[i]->GetComponent<Texture>()->currentTextureID = AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->animations[(int)AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation][(int)((TimeManager::Get()->GetCurrentTime() - AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->timeWhenCurrentAnimationStarted) / AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->frameTime) % AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->animations[(int)AnimationStorage::Get()->entities[i]->GetComponent<Animation>()->currentEntityAnimation].size()];
		}
	}

private:

	static AnimationManager* instance;

	AnimationManager() {};

	AnimationManager(const AnimationManager&) = delete;
};

AnimationManager* AnimationManager::instance = nullptr;

// CLASA BEHAVIOUR MANAGER

class BehaviourManager
{
public:

	static BehaviourManager* Get()
	{
		if (BehaviourManager::instance == nullptr)
		{
			BehaviourManager::instance = new BehaviourManager();
		}

		return BehaviourManager::instance;
	}

	void UpdateBehaviour()
	{
		for (int i = 0; i < BehaviourStorage::Get()->entities.size(); i++)
		{
			bool isOK = true;

			if (BehaviourStorage::Get()->entities[i]->GetComponent<Behaviour>()->target == nullptr)
			{
				std::cout << "ERROR :: BEHAVIOUR MANAGER :: UPDATEBEHAVIOUR :: THERE IS AN ENTITY WITHOUT A TARGET FOR BEHAVIOUR. CAN NOT UPDATE BEHAVIOUR\n";

				isOK = false;
			}
			if (!BehaviourStorage::Get()->entities[i]->GetComponent<Behaviour>()->target->HasComponent<Position>())
			{
				std::cout << "ERROR :: BEHAVIOUR MANAGER :: UPDATEBEHAVIOUR :: THERE IS AN ENTITY WHICH POSSESSES A TARGET WITHOUT POSITION COMPONENT. CAN NOT UPDATE BEHAVIOUR\n";

				isOK = false;
			}
			if (!BehaviourStorage::Get()->entities[i]->HasComponent<Position>())
			{
				std::cout << "ERROR :: BEHAVIOUR MANAGER :: UPDATEBEHAVIOUR :: THERE IS AN ENTITY WITHOUT POSITION COMPONENT. CAN NOT APPLY BEHAVIOUR\n";

				isOK = false;
			}
			if (!BehaviourStorage::Get()->entities[i]->HasComponent<Speed>())
			{
				std::cout << "ERROR :: BEHAVIOUR MANAGER :: UPDATEBEHAVIOUR :: THERE IS AN ENTITY WITHOUT SPEED COMPONENT. CAN NOT APPLY BEHAVIOUR\n";

				isOK = false;
			}
			if (!BehaviourStorage::Get()->entities[i]->HasComponent<MovementSpeed>())
			{
				std::cout << "ERROR :: BEHAVIOUR MANAGER :: UPDATEBEHAVIOUR :: THERE IS AN ENTITY WITHOUT MOVEMENTSPEED COMPONENT. CAN NOT APPLY BEHAVIOUR\n";

				isOK = false;
			}

			if (!isOK) continue;

			if (BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentRight)
			{
				BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentRight = false;

				BehaviourStorage::Get()->entities[i]->GetComponent<Speed>()->speedX -= BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;
			}

			if (BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentLeft)
			{
				BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentLeft = false;

				BehaviourStorage::Get()->entities[i]->GetComponent<Speed>()->speedX += BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;
			}

			if (BehaviourStorage::Get()->entities[i]->GetComponent<Behaviour>()->state == EntityBehaviour::passive) // DACA ENTITATEA ESTE PASIVA FATA DE JUCATOR
			{

			}
			else if (BehaviourStorage::Get()->entities[i]->GetComponent<Behaviour>()->state == EntityBehaviour::aggresive) // DACA ENTITATEA ESTE AGRESIVA FATA DE JUCATOR
			{
				if (BehaviourStorage::Get()->entities[i]->GetComponent<Behaviour>()->target->GetComponent<Position>()->x < BehaviourStorage::Get()->entities[i]->GetComponent<Position>()->x - ENTITY_BEHAVIOUR_CONSTANT::AGGRESIVE_EPSILON_X)
				{

					BehaviourStorage::Get()->entities[i]->GetComponent<Speed>()->speedX -= BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;

					BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentLeft = true;

					///*
					if (BehaviourStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward)
					{
						BehaviourStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward = false;

						BehaviourStorage::Get()->entities[i]->GetComponent<Speed>()->speedY += BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedY;
					}
					//*/
				}

				if (BehaviourStorage::Get()->entities[i]->GetComponent<Behaviour>()->target->GetComponent<Position>()->x > BehaviourStorage::Get()->entities[i]->GetComponent<Position>()->x + ENTITY_BEHAVIOUR_CONSTANT::AGGRESIVE_EPSILON_X)
				{

					BehaviourStorage::Get()->entities[i]->GetComponent<Speed>()->speedX += BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedX;

					BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->wentRight = true;

					///*
					if (BehaviourStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward)
					{
						BehaviourStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward = false;

						BehaviourStorage::Get()->entities[i]->GetComponent<Speed>()->speedY += BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedY;
					}
					//*/
				}

				if (BehaviourStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward && BehaviourStorage::Get()->entities[i]->GetComponent<Behaviour>()->target->GetComponent<Position>()->y > BehaviourStorage::Get()->entities[i]->GetComponent<Position>()->y + ENTITY_BEHAVIOUR_CONSTANT::AGGRESIVE_EPSILON_Y)
				{
					BehaviourStorage::Get()->entities[i]->GetComponent<Hitbox>()->collidedDownward = false;

					BehaviourStorage::Get()->entities[i]->GetComponent<Speed>()->speedY += BehaviourStorage::Get()->entities[i]->GetComponent<MovementSpeed>()->speedY;
				}
			}
		}
	}

private:

	static BehaviourManager* instance;

	BehaviourManager() {};
};

BehaviourManager* BehaviourManager::instance = nullptr;

// CLASA GAME ENGINE

class GameEngine
{
public:

	static GameEngine* Get()
	{
		if (GameEngine::instance == nullptr)
		{
			GameEngine::instance = new GameEngine();
		}

		return GameEngine::instance;
	}

	void Start(int windowWidth, int windowHeight, std::string gameTitle)
	{
		WindowManager::Get()->CreateWindow(windowWidth, windowHeight, gameTitle);

		TimeManager::Get();
	}

	void Update()
	{
		WindowManager::Get()->UpdateWindow();

		TimeManager::Get()->UpdateDeltaTime();

		InputManager::Get()->ListenForInput();

		MovementManager::Get()->UpdateMovements();

		CollisionManager::Get()->UpdateCollisions();

		AnimationManager::Get()->UpdateAnimations();

		BehaviourManager::Get()->UpdateBehaviour();

		if (InputManager::Get()->ShouldGameEngineStop())
		{
			this->isRunning = false;
		}
	}

	void Stop()
	{
		WindowManager::Get()->SetWindowShouldClose(true);
		WindowManager::Get()->DestroyWindow();

		this->isRunning = false;
	}

	bool ShouldGameEngineStop()
	{
		return !isRunning;
	}

private:

	static GameEngine* instance;

	bool isRunning;

	GameEngine()
	{
		this->isRunning = true;
	}

	GameEngine(const GameEngine&) = delete;
};

GameEngine* GameEngine::instance = nullptr;