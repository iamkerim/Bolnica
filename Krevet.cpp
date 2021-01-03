#include "Krevet.h"

Krevet::Krevet()
{
	this->status = slobodno;
}

void Krevet::setBroj(int a)
{
	this->broj = a;
}

void Krevet::setStatus(Status x)
{
	this->status = x;
}

int Krevet::getBroj()
{
	return this->broj;
}

Status Krevet::getStatus()
{
	return this->status;
}

void Krevet::postaviKrevet(int a, Status x)
{
	this->setBroj(a);
	this->setStatus(x);
}

Krevet::~Krevet()
{
}
