#ifndef CHEESE_H
#define CHEESE_H


class Actor;
class Mouse;

class Cheese {
private:
	char icon;
	bool eat_now;
	int remaining;
	int row;
	int col;

	char get_icon() const;
	int get_remaining() const;
	void decrease_remaining(int amount);

public:
	Cheese(int row_, int col_, char icon_, int remaining_, bool eat_now);
	~Cheese();
	int get_row() const;
	int get_col() const;
	void set_row(int r);
	void set_col(int c);
	virtual void cheese_behavior(Mouse* mouse) = 0;
	virtual	bool is_poisoned() const = 0;
};

class PureCheese : public Cheese {
public:
	PureCheese(int row_, int col_, char icon_);
	~PureCheese();
	virtual bool is_poisoned() const;
	virtual void cheese_behavior(Mouse* mouse) = 0;
};

class DoorCheese : public PureCheese {
public:
	DoorCheese(int row_, int col_);
	~DoorCheese();
	virtual void cheese_behavior(Mouse* mouse);
};


class EscapeCheese : public PureCheese {
public:
	EscapeCheese(int row_, int col_);
	~EscapeCheese();
	virtual void cheese_behavior(Mouse* mouse);
};



class HealthCheese : public PureCheese {
public:
	HealthCheese(int row_, int col_);
	~HealthCheese();
	virtual void cheese_behavior(Mouse* mouse);
};

class MirrorCheese : public PureCheese {
public:
	MirrorCheese(int row_, int col_);
	~MirrorCheese();
	virtual void cheese_behavior(Mouse* mouse);
};

//class SpitCheese : public PureCheese {
//public:
//	SpitCheese(int row_, int col_);
//	~SpitCheese();
//	virtual void cheese_behavior(Mouse* mouse);
//};


class GeneralCheese : public Cheese {
private:
	bool poisoned;
public:
	GeneralCheese(int row_, int col_); //set poisoned randomly to true
	~GeneralCheese();
	virtual void cheese_behavior(Mouse* mouse);
	bool is_poisoned() const; //return poisoned
//	int randInt(int limit);
};

#endif