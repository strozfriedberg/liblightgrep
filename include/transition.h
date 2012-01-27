#pragma once

#include "basic.h"

#include <boost/shared_ptr.hpp>

class Instruction;

class Transition {
public:
  Transition() {}
  virtual ~Transition() {}

  virtual const byte* allowed(const byte* beg, const byte* end) const = 0;
  virtual void getBits(ByteSet& bitvec) const = 0;
  virtual byte type() const = 0;
  virtual size_t objSize() const = 0;
  virtual Transition* clone(void* buffer = 0) const = 0;
  virtual size_t numInstructions() const = 0;
  virtual bool toInstruction(Instruction* addr) const = 0;
  virtual std::string label() const = 0;

private:
  Transition(const Transition&) {}
  Transition& operator=(const Transition&) {return *this;}
};

typedef boost::shared_ptr<Transition> TransitionPtr;

