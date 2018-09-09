#pragma once  
#define FREEGLUT_STATIC
#define GLUT_DISABLE_ATEXIT_HACK  
#include "vec.h"
#include <gl/glut.h>
#include <iostream>
using namespace std;


class particle {
	bool has_tex;//�������ɫ 

	vec place;//λ��
	vec size;//��С
	vec speed;// �ٶ�
	vec acc;//���ٶ� 
	vec angle;//�Ƕ�
	vec color;//��ɫ

	unsigned int texture;//����  
	float life;//���� 
	friend class emitter;

	void draw(GLuint texture);//�������ӣ�����  
	void draw();//�������ӣ���ɫ��
	void show();
	void update();

public:
	const vec& getPlace();
	const vec& getSize();
	const vec& getAngle();
	particle(vec size, vec speed, vec acc, vec angle,
		float _life, unsigned int _texture);

	particle(vec size, vec speed, vec acc, vec angle,
		float _life, vec _color);
};

class emitter {
	float x1, y1, x2, y2, z1, z2; //������λ��  
	int speed;//��������  
	bool isforever;
	int num;
	particle **p;//��������  
	bool *dead;
	particle* (*f)();
	//��ʼ�����ӵĺ���ָ��  
	bool(*isDead)(particle*);

public:
	void emit(float _x1,
		float _x2, float _y1, float _y2, float _z1, float _z2);
	void update();
	void show();
	emitter(particle* (init)(), int _speed, float _x1,
		float _x2, float _y1, float _y2, float _z1, float _z2);
	~emitter();
};