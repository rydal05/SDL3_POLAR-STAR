class TreeModel { // not specific to a single instance
private:
	Mesh mesh_;
	Texture bark_;
	Texture leaves_;
};

class Tree { // Specific to a single instance
private:
	TreeModel *model_; // pointer to the model itself

	Vector position_; // specifics can be established per class
	double height_;
	double thickness_;
	Color barkTint_;
	Color leafTint_;
};

enum Terrain {
	TERRAIN_GRASS,
	TERRAIN_HILL,
	TERRAIN_RIVER
	// etc..
};

class World {
private:
	Terrain *tiles_[WIDTH][HEIGHT];
};

/*
const methods; used when the same object is used in multiple contexts,
should you modify it, changes would appear in multiple places simultaneously
*/
// factory method
// object pooling

class Observer {
public:
	virtual ~Observer() {}
	virtual void onNotify(const Entity &entity, Event event) = 0;
};

class Subject {
private:
	Observer *observers_[MAX_OBSERVERS]; // would use dynalloc array instead of fixed size
	int numObservers_;

public:
	void addObserver(Observer *observer) {
	}

	void removeObserver(Observer *observer) {
	}

protected:
	void notify(const Entity &entity, Event event) {
		for (int i = 0; i < numObservers_; i++) {
			observers_[i]->onNotify(entity, event);
		}
	}
};

// linked observer construction

class LinkedSubject {
	LinkedSubject() : head_(NULL) {}

private:
	Observer *head_;
};

class Observer {
	friend class LinkedSubject;

public:
	Observer() : next_(NULL) {}

    private:
    Observer* next_;
};

