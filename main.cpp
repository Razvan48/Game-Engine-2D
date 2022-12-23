#include "GameEngine2D/GameEngine2D.h"

int main()
{
	GameEngine::Get()->Start(1024, 1024, "GameEngine2D");

	WindowManager::Get()->SetClearColor(0.07843137, 0.33333333, 0.39607843);

	Renderer* fullRectangleRenderer2D = new Renderer("GameEngine2D/Shaders/FullRectangleShader/FullRectangleVertexShader.txt", "GameEngine2D/Shaders/FullRectangleShader/FullRectangleFragmentShader.txt");
	Renderer* noFullRectangleRenderer2D = new Renderer("GameEngine2D/Shaders/NoFullRectangleShader/NoFullRectangleVertexShader.txt", "GameEngine2D/Shaders/NoFullRectangleShader/NoFullRectangleFragmentShader.txt");

	AssetManager::Get()->AddTexture("Terrain0", "GameEngine2D/Textures/Terrain/Terrain0.png");

	Entity* terrain0 = new Entity(EntityType::terrain);
	terrain0->AddComponent(new Position(350, 550.0));
	terrain0->AddComponent(new Hitbox(750.0, 150.0));
	terrain0->AddComponent(new Texture());
	terrain0->GetComponent<Texture>()->currentTextureID = AssetManager::Get()->GetTextureID("Terrain0");
	terrain0->AddComponent(new TextureBox(750.0, 150.0));
	terrain0->AddComponent(new Render());

	Entity* terrain1 = new Entity(EntityType::terrain);
	terrain1->AddComponent(new Position(750, 100.0));
	terrain1->AddComponent(new Hitbox(250.0, 150.0));
	terrain1->AddComponent(new Texture());
	terrain1->GetComponent<Texture>()->currentTextureID = AssetManager::Get()->GetTextureID("Terrain0");
	terrain1->AddComponent(new TextureBox(250.0, 150.0));
	terrain1->AddComponent(new Render());

	Entity* terrain2 = new Entity(EntityType::terrain);
	terrain2->AddComponent(new Position(350, 100.0));
	terrain2->AddComponent(new Hitbox(250.0, 150.0));
	terrain2->AddComponent(new Texture());
	terrain2->GetComponent<Texture>()->currentTextureID = AssetManager::Get()->GetTextureID("Terrain0");
	terrain2->AddComponent(new TextureBox(250.0, 150.0));
	terrain2->AddComponent(new Render());

	Entity* terrain3 = new Entity(EntityType::terrain);
	terrain3->AddComponent(new Position(350, 0.0));
	terrain3->AddComponent(new Hitbox(750.0, 150.0));
	terrain3->AddComponent(new Texture());
	terrain3->GetComponent<Texture>()->currentTextureID = AssetManager::Get()->GetTextureID("Terrain0");
	terrain3->AddComponent(new TextureBox(750.0, 150.0));
	terrain3->AddComponent(new Render());

	AssetManager::Get()->AddTexture("Terrain1", "GameEngine2D/Textures/Terrain/Terrain1.png");

	Entity* terrain4 = new Entity(EntityType::terrain);
	terrain4->AddComponent(new Position(1250, 0.0));
	terrain4->AddComponent(new Hitbox(350.0, 1.0));
	terrain4->AddComponent(new Texture());
	terrain4->GetComponent<Texture>()->currentTextureID = AssetManager::Get()->GetTextureID("Terrain1");
	terrain4->AddComponent(new TextureBox(350.0, 250.0));
	terrain4->AddComponent(new Render());

	AssetManager::Get()->AddTexture("Sky0", "GameEngine2D/Textures/Sky/Sky0.png");

	Entity* sky0 = new Entity(EntityType::landscape);
	sky0->AddComponent(new Position(512.0, 512.0));
	sky0->AddComponent(new Texture());
	sky0->GetComponent<Texture>()->currentTextureID = AssetManager::Get()->GetTextureID("Sky0");
	sky0->AddComponent(new TextureBox(1024.0, 1024.0));
	sky0->AddComponent(new Render());

	Entity* character0 = new Entity(EntityType::character);

	character0->AddComponent(new Position(350.0, 750.0));
	character0->AddComponent(new Hitbox(40.0, 100.0));
	character0->AddComponent(new Texture());
	character0->AddComponent(new TextureBox(100.0, 100.0));
	character0->AddComponent(new Render());
	character0->AddComponent(new Speed(0.0, 0.0));
	character0->AddComponent(new MovementSpeed(250.0, 450.0));
	character0->AddComponent(new Animation(0.1));
	character0->AddComponent(new Gravity(-150.0));
	character0->AddComponent(new Input());

	Camera::Get()->FollowEntity(character0);

	AssetManager::Get()->AddTexture("RedStickmanStanding0", "GameEngine2D/Textures/Animations/RedStickman/Standing/Standing0.png");
	AssetManager::Get()->AddTexture("RedStickmanStanding1", "GameEngine2D/Textures/Animations/RedStickman/Standing/Standing1.png");
	AssetManager::Get()->AddTexture("RedStickmanStanding2", "GameEngine2D/Textures/Animations/RedStickman/Standing/Standing2.png");
	AssetManager::Get()->AddTexture("RedStickmanStanding3", "GameEngine2D/Textures/Animations/RedStickman/Standing/Standing3.png");
	AssetManager::Get()->AddTexture("RedStickmanStanding4", "GameEngine2D/Textures/Animations/RedStickman/Standing/Standing4.png");
	AssetManager::Get()->AddTexture("RedStickmanStanding5", "GameEngine2D/Textures/Animations/RedStickman/Standing/Standing5.png");
	AssetManager::Get()->AddTexture("RedStickmanStanding6", "GameEngine2D/Textures/Animations/RedStickman/Standing/Standing6.png");

	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("RedStickmanStanding0"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("RedStickmanStanding1"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("RedStickmanStanding2"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("RedStickmanStanding3"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("RedStickmanStanding4"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("RedStickmanStanding5"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("RedStickmanStanding6"));

	AssetManager::Get()->AddTexture("RedStickmanWalkingRight0", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking0.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight1", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking1.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight2", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking2.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight3", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking3.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight4", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking4.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight5", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking5.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight6", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking6.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight7", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking7.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight8", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking8.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight9", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking9.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight10", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking10.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight11", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking11.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight12", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking12.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingRight13", "GameEngine2D/Textures/Animations/RedStickman/WalkingRight/Walking13.png");

	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight0"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight1"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight2"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight3"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight4"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight5"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight6"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight7"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight8"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight9"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight10"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight11"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight12"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingRight13"));

	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft0", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking0.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft1", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking1.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft2", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking2.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft3", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking3.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft4", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking4.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft5", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking5.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft6", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking6.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft7", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking7.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft8", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking8.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft9", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking9.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft10", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking10.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft11", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking11.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft12", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking12.png");
	AssetManager::Get()->AddTexture("RedStickmanWalkingLeft13", "GameEngine2D/Textures/Animations/RedStickman/WalkingLeft/Walking13.png");

	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft0"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft1"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft2"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft3"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft4"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft5"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft6"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft7"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft8"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft9"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft10"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft11"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft12"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanWalkingLeft13"));

	AssetManager::Get()->AddTexture("RedStickmanJumpingRight0", "GameEngine2D/Textures/Animations/RedStickman/JumpingRight/Jumping0.png");
	AssetManager::Get()->AddTexture("RedStickmanJumpingRight1", "GameEngine2D/Textures/Animations/RedStickman/JumpingRight/Jumping1.png");
	AssetManager::Get()->AddTexture("RedStickmanJumpingRight2", "GameEngine2D/Textures/Animations/RedStickman/JumpingRight/Jumping2.png");
	AssetManager::Get()->AddTexture("RedStickmanJumpingRight3", "GameEngine2D/Textures/Animations/RedStickman/JumpingRight/Jumping3.png");

	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingRight0"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingRight1"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingRight2"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingRight3"));

	AssetManager::Get()->AddTexture("RedStickmanJumpingLeft0", "GameEngine2D/Textures/Animations/RedStickman/JumpingLeft/Jumping0.png");
	AssetManager::Get()->AddTexture("RedStickmanJumpingLeft1", "GameEngine2D/Textures/Animations/RedStickman/JumpingLeft/Jumping1.png");
	AssetManager::Get()->AddTexture("RedStickmanJumpingLeft2", "GameEngine2D/Textures/Animations/RedStickman/JumpingLeft/Jumping2.png");
	AssetManager::Get()->AddTexture("RedStickmanJumpingLeft3", "GameEngine2D/Textures/Animations/RedStickman/JumpingLeft/Jumping3.png");

	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingLeft0"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingLeft1"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingLeft2"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanJumpingLeft3"));

	AssetManager::Get()->AddTexture("RedStickmanFallingRight0", "GameEngine2D/Textures/Animations/RedStickman/FallingRight/Falling0.png");
	AssetManager::Get()->AddTexture("RedStickmanFallingRight1", "GameEngine2D/Textures/Animations/RedStickman/FallingRight/Falling1.png");
	AssetManager::Get()->AddTexture("RedStickmanFallingRight2", "GameEngine2D/Textures/Animations/RedStickman/FallingRight/Falling2.png");
	AssetManager::Get()->AddTexture("RedStickmanFallingRight3", "GameEngine2D/Textures/Animations/RedStickman/FallingRight/Falling3.png");

	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingRight0"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingRight1"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingRight2"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingRight3"));

	AssetManager::Get()->AddTexture("RedStickmanFallingLeft0", "GameEngine2D/Textures/Animations/RedStickman/FallingLeft/Falling0.png");
	AssetManager::Get()->AddTexture("RedStickmanFallingLeft1", "GameEngine2D/Textures/Animations/RedStickman/FallingLeft/Falling1.png");
	AssetManager::Get()->AddTexture("RedStickmanFallingLeft2", "GameEngine2D/Textures/Animations/RedStickman/FallingLeft/Falling2.png");
	AssetManager::Get()->AddTexture("RedStickmanFallingLeft3", "GameEngine2D/Textures/Animations/RedStickman/FallingLeft/Falling3.png");

	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingLeft0"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingLeft1"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingLeft2"));
	character0->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("RedStickmanFallingLeft3"));

	Entity* character1 = new Entity(EntityType::character);

	character1->AddComponent(new Position(800.0, 350.0));
	character1->AddComponent(new Hitbox(40.0, 100.0));
	character1->AddComponent(new Texture());
	character1->AddComponent(new TextureBox(100.0, 100.0));
	character1->AddComponent(new Render());
	character1->AddComponent(new Speed(0.0, 0.0));
	character1->AddComponent(new MovementSpeed(175.0, 350.0));
	character1->AddComponent(new Animation(0.1));
	character1->AddComponent(new Gravity(-150.0));
	character1->AddComponent(new Behaviour(EntityBehaviour::aggresive, character0));

	AssetManager::Get()->AddTexture("PinkStickmanStanding0", "GameEngine2D/Textures/Animations/PinkStickman/Standing/Standing0.png");
	AssetManager::Get()->AddTexture("PinkStickmanStanding1", "GameEngine2D/Textures/Animations/PinkStickman/Standing/Standing1.png");
	AssetManager::Get()->AddTexture("PinkStickmanStanding2", "GameEngine2D/Textures/Animations/PinkStickman/Standing/Standing2.png");
	AssetManager::Get()->AddTexture("PinkStickmanStanding3", "GameEngine2D/Textures/Animations/PinkStickman/Standing/Standing3.png");
	AssetManager::Get()->AddTexture("PinkStickmanStanding4", "GameEngine2D/Textures/Animations/PinkStickman/Standing/Standing4.png");
	AssetManager::Get()->AddTexture("PinkStickmanStanding5", "GameEngine2D/Textures/Animations/PinkStickman/Standing/Standing5.png");
	AssetManager::Get()->AddTexture("PinkStickmanStanding6", "GameEngine2D/Textures/Animations/PinkStickman/Standing/Standing6.png");

	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("PinkStickmanStanding0"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("PinkStickmanStanding1"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("PinkStickmanStanding2"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("PinkStickmanStanding3"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("PinkStickmanStanding4"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("PinkStickmanStanding5"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::standing].push_back(AssetManager::Get()->GetTextureID("PinkStickmanStanding6"));

	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight0", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking0.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight1", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking1.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight2", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking2.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight3", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking3.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight4", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking4.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight5", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking5.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight6", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking6.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight7", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking7.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight8", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking8.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight9", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking9.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight10", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking10.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight11", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking11.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight12", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking12.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingRight13", "GameEngine2D/Textures/Animations/PinkStickman/WalkingRight/Walking13.png");

	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight0"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight1"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight2"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight3"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight4"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight5"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight6"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight7"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight8"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight9"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight10"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight11"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight12"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingRight13"));

	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft0", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking0.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft1", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking1.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft2", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking2.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft3", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking3.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft4", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking4.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft5", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking5.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft6", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking6.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft7", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking7.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft8", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking8.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft9", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking9.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft10", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking10.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft11", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking11.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft12", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking12.png");
	AssetManager::Get()->AddTexture("PinkStickmanWalkingLeft13", "GameEngine2D/Textures/Animations/PinkStickman/WalkingLeft/Walking13.png");

	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft0"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft1"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft2"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft3"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft4"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft5"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft6"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft7"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft8"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft9"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft10"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft11"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft12"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::walkingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanWalkingLeft13"));

	AssetManager::Get()->AddTexture("PinkStickmanJumpingRight0", "GameEngine2D/Textures/Animations/PinkStickman/JumpingRight/Jumping0.png");
	AssetManager::Get()->AddTexture("PinkStickmanJumpingRight1", "GameEngine2D/Textures/Animations/PinkStickman/JumpingRight/Jumping1.png");
	AssetManager::Get()->AddTexture("PinkStickmanJumpingRight2", "GameEngine2D/Textures/Animations/PinkStickman/JumpingRight/Jumping2.png");
	AssetManager::Get()->AddTexture("PinkStickmanJumpingRight3", "GameEngine2D/Textures/Animations/PinkStickman/JumpingRight/Jumping3.png");

	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingRight0"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingRight1"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingRight2"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingRight3"));

	AssetManager::Get()->AddTexture("PinkStickmanJumpingLeft0", "GameEngine2D/Textures/Animations/PinkStickman/JumpingLeft/Jumping0.png");
	AssetManager::Get()->AddTexture("PinkStickmanJumpingLeft1", "GameEngine2D/Textures/Animations/PinkStickman/JumpingLeft/Jumping1.png");
	AssetManager::Get()->AddTexture("PinkStickmanJumpingLeft2", "GameEngine2D/Textures/Animations/PinkStickman/JumpingLeft/Jumping2.png");
	AssetManager::Get()->AddTexture("PinkStickmanJumpingLeft3", "GameEngine2D/Textures/Animations/PinkStickman/JumpingLeft/Jumping3.png");

	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingLeft0"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingLeft1"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingLeft2"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::jumpingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanJumpingLeft3"));

	AssetManager::Get()->AddTexture("PinkStickmanFallingRight0", "GameEngine2D/Textures/Animations/PinkStickman/FallingRight/Falling0.png");
	AssetManager::Get()->AddTexture("PinkStickmanFallingRight1", "GameEngine2D/Textures/Animations/PinkStickman/FallingRight/Falling1.png");
	AssetManager::Get()->AddTexture("PinkStickmanFallingRight2", "GameEngine2D/Textures/Animations/PinkStickman/FallingRight/Falling2.png");
	AssetManager::Get()->AddTexture("PinkStickmanFallingRight3", "GameEngine2D/Textures/Animations/PinkStickman/FallingRight/Falling3.png");

	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingRight0"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingRight1"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingRight2"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingRight].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingRight3"));

	AssetManager::Get()->AddTexture("PinkStickmanFallingLeft0", "GameEngine2D/Textures/Animations/PinkStickman/FallingLeft/Falling0.png");
	AssetManager::Get()->AddTexture("PinkStickmanFallingLeft1", "GameEngine2D/Textures/Animations/PinkStickman/FallingLeft/Falling1.png");
	AssetManager::Get()->AddTexture("PinkStickmanFallingLeft2", "GameEngine2D/Textures/Animations/PinkStickman/FallingLeft/Falling2.png");
	AssetManager::Get()->AddTexture("PinkStickmanFallingLeft3", "GameEngine2D/Textures/Animations/PinkStickman/FallingLeft/Falling3.png");

	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingLeft0"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingLeft1"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingLeft2"));
	character1->GetComponent<Animation>()->animations[(int)EntityAnimation::fallingLeft].push_back(AssetManager::Get()->GetTextureID("PinkStickmanFallingLeft3"));


	while (!GameEngine::Get()->ShouldGameEngineStop())
	{
		GameEngine::Get()->Update();

		// AICI COD (TREBUIE INTR-O ORDINE DESENATE ENTITATILE PE ECRAN, ALGORITMUL PICTORULUI

		// CER
		sky0->GetComponent<Render>()->Draw(fullRectangleRenderer2D);

		// TEREN
		terrain0->GetComponent<Render>()->Draw(fullRectangleRenderer2D);
		terrain1->GetComponent<Render>()->Draw(fullRectangleRenderer2D);
		terrain2->GetComponent<Render>()->Draw(fullRectangleRenderer2D);
		terrain3->GetComponent<Render>()->Draw(fullRectangleRenderer2D);
		terrain4->GetComponent<Render>()->Draw(noFullRectangleRenderer2D);

		// CARACTERE / PERSONAJE
		character0->GetComponent<Render>()->Draw(noFullRectangleRenderer2D);
		character1->GetComponent<Render>()->Draw(noFullRectangleRenderer2D);

		std::cout << 1.0 / TimeManager::Get()->GetDeltaTime() << '\n';
	}

	GameEngine::Get()->Stop();

	return 0;
}