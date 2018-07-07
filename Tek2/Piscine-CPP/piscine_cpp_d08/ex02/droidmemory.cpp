//
// droidmemory.cpp for droidmemory in /home/pereni_j/Rendu/piscine_cpp_d08/ex01
// 
// Made by pereniguez joseph
// Login   <pereni_j@epitech.net>
// 
// Started on  Wed Jan 13 18:27:27 2016 pereniguez joseph
// Last update Wed Jan 13 21:38:03 2016 pereniguez joseph
//

#include "droidmemory.hh"

DroidMemory::DroidMemory() : Exp(0)
{
  FingerPrint = random();
}

DroidMemory::~DroidMemory()
{
}

std::ostream&		operator<<(std::ostream& os, DroidMemory const & k)
{
  os << "DroidMemory '" << k.getFingerPrint() << "', " << k.getExp();
  return os;
}

void			DroidMemory::fusion(DroidMemory &pos, DroidMemory const &k1, DroidMemory const &k2)
{
  pos.Exp = k1.Exp + k2.Exp;
  pos.FingerPrint = k1.FingerPrint ^ k2.FingerPrint;
}

DroidMemory&		DroidMemory::operator+(size_t experience) const
{
  DroidMemory memory;
  memory.Exp = experience;
  memory.FingerPrint = experience;
  DroidMemory *ptr = new DroidMemory();
  DroidMemory::fusion(*ptr, *this, memory);
  return *ptr;
}

DroidMemory&		DroidMemory::operator<<(DroidMemory const & k)
{
  DroidMemory::fusion(*this, *this, k);
  return *this;
}

DroidMemory const &	DroidMemory::operator>>(DroidMemory & k) const
{
  DroidMemory::fusion(k, *this, k);
  return *this;
}

DroidMemory&		DroidMemory::operator+=(DroidMemory const & k)
{
  DroidMemory::fusion(*this, *this, k);
  return *this;
}

DroidMemory&		DroidMemory::operator+=(size_t experience)
{
  DroidMemory memory;
  memory.Exp = experience;
  memory.FingerPrint = experience;
  DroidMemory::fusion(*this, *this, memory);
  return *this;
}

DroidMemory&		DroidMemory::operator+(DroidMemory const & k) const
{
  DroidMemory *ptr = new DroidMemory();
  DroidMemory::fusion(*ptr, *this, k);
  return *ptr;
}

void			DroidMemory::setFingerPrint(size_t print)
{
  this->FingerPrint = print;
}

size_t			DroidMemory::getFingerPrint() const
{
  return FingerPrint;
}

void			DroidMemory::setExp(size_t experience)
{
  this->Exp = experience;
}

size_t			DroidMemory::getExp() const
{
  return Exp;
}
