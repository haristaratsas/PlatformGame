#pragma once

#include "gameobject.h"
#include <sgg/graphics.h>
#include "timer.h"
#include "CollisionObject.h"

class Player : public CollisionObject, public GameObject
{
	// animated player
	std::vector<std::string> m_spritesright;
	std::vector<std::string> m_spritesleft;
	std::vector<std::string> m_spritesidle;
	std::vector<std::string> m_spritesjumpright;
	std::vector<std::string> m_spritesjumpleft;
	std::vector<std::string> m_spritesdeactivation;
	std::vector<std::string> m_spritesattackwithkniferight;
	std::vector<std::string> m_spritesattackwithknifeleft;
	graphics::MouseState mouse;
	graphics::Brush m_brush_player;
	const float m_accel_horizontal = 20.0f;
	const float m_accel_vertical = 300.1f;
	const float m_max_velocity = 5.0f;
	const float m_gravity = 12.0f;
	float animationtimerfordeath = 0.0f;
	float animationtimerforafk = 0.0f;
	float animationtimerforattackwithknife = 0.0f;
	bool isAnimationPlaying = false;
	

public:
	float m_vx = 5.0f;
	float m_vy = 0.0f;
	float offsetmvy;
	int m_player_health = 5;
	bool m_gameover = false;

public:
	void update(float dt) override;
	void draw() override;
	void init() override;
	Player(std::string name) : GameObject(name) {}

protected:
	void debugDraw();

	// dynamic motion control
	void movePlayer(float dt);
	//dynamic health control
	void hurtPlayer();
	void attackEnemy();

};