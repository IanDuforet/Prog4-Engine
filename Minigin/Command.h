#pragma once
#include "ControlComponent.h"
#include "MiniginPCH.h"

namespace elfgine
{
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) = 0;
	};
	
	class MoveLeft final : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveLeft(); };
	};
	
	class MoveRight final : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveRight(); };
	};
	
	class MoveUp final : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveUp(); };
	};
	
	class MoveDown final : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveDown(); };
	};

	class Shoot final : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->Shoot(); };
	};
}

