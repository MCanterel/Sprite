#include "Character.h"

Character::Character(const Vec2 & pos)
	:
	sprite("Images//link90x90.bmp"),
	pos(pos),
	width(90),
	height(90)
{
	for (int i = 0; i < (int)Sequence::StandingLeft; i++)
	{
		animations.emplace_back(Animation(90, 90 * i, 90, 90, 4, sprite, 0.15f));
	}
	for (int i = (int)Sequence::StandingLeft; i < (int)Sequence::Count; i++)
	{
		animations.emplace_back(Animation(0, 90 * (i - (int)Sequence::StandingLeft), 90, 90, 1, sprite, 0.15f));
	}
}

void Character::Update(float dt)
{
	pos += vel * dt;
	animations[(int)iCurSequence].Update(dt);
}

void Character::SetDirection(const Vec2 & dir)
{
	if (dir.x > 0.0f) {
		iCurSequence = Sequence::WalkingRight;
	}
	else if (dir.x < 0.0f) {
		iCurSequence = Sequence::WalkingLeft;
	}
	else if (dir.y > 0.0f) {
		iCurSequence = Sequence::WalkingDown;
	}
	else if (dir.y < 0.0f) {
		iCurSequence = Sequence::WalkingUp;
	}
	else {
		if (vel.x > 0) {
			iCurSequence = Sequence::StandingRight;
		}
		if (vel.x < 0) {
			iCurSequence = Sequence::StandingLeft;
		}
		if (vel.y > 0) {
			iCurSequence = Sequence::StandingDown;
		}
		if (vel.y < 0) {
			iCurSequence = Sequence::StandingUp;
		}
	}
	vel = dir * speed;
}

void Character::SetDirection(const Mouse& mouse)
{
	const Vec2 center = pos + Vec2(float(width) / 2.0f, float(height) / 2.0f);
	const Vec2 toPointer = Vec2(float(mouse.GetPosX()), float(mouse.GetPosY())) - center;

	if (toPointer.x > 0.0f) {
		iCurSequence = Sequence::WalkingRight;
	}
	else if (toPointer.x < 0.0f) {
		iCurSequence = Sequence::WalkingLeft;
	}
	else if (toPointer.y > 0.0f) {
		iCurSequence = Sequence::WalkingDown;
	}
	else if (toPointer.y < 0.0f) {
		iCurSequence = Sequence::WalkingUp;
	}
	else {
		if (vel.x > 0) {
			iCurSequence = Sequence::StandingRight;
		}
		if (vel.x < 0) {
			iCurSequence = Sequence::StandingLeft;
		}
		if (vel.y > 0) {
			iCurSequence = Sequence::StandingDown;
		}
		if (vel.y < 0) {
			iCurSequence = Sequence::StandingUp;
		}
	}
	if (toPointer.GetLengthSq() > 40.0f) {
		vel = toPointer.GetNormalized() * speed;
	}


}

void Character::Draw(Graphics & gfx) const
{
	animations[(int)iCurSequence].Draw((Vei2)pos, gfx);
}
