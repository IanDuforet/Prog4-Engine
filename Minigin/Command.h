#pragma once
#include "ControlComponent.h"
namespace elfgine
{
	class Command
	{
	public:
		virtual ~Command() = default;
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) = 0;
	};
	
	class MoveLeft : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveLeft(); };
	};
	
	class MoveRight : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveRight(); };
	};
	
	class MoveUp : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveUp(); };
	};
	
	class MoveDown : public Command
	{
	public:
		virtual void execute(std::weak_ptr<ControlComponent> pToControl) { pToControl.lock()->MoveDown(); };
	};
}

