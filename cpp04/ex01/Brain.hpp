#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain {
  public:
  Brain();
  Brain(const Brain &other);
  ~Brain();
  Brain &operator=(const Brain &rhs);

  private:
};

Brain::Brain() {
}

Brain::Brain(const Brain &other) {
  *this = other;
}

Brain::~Brain() {
}

Brain &Brain::operator=(const Brain &rhs) {
  if (this == &rhs)
    return *this;

  return *this;
}

#endif  // BRAIN_HPP