// Constructor with id, coordinates and dof
//! \param[in] id Node id
//! \param[in] coord coordinates of the node
//! \param[in] dof Degrees of freedom
//! \tparam Tdim Dimension
//! \tparam Tdof Degrees of Freedom
//! \tparam Tnphases Number of phases
template <unsigned Tdim, unsigned Tdof, unsigned Tnphases>
mpm::Node<Tdim, Tdof, Tnphases>::Node(Index id, const Eigen::Matrix<double, Tdim, 1>& coord)
    : NodeBase<Tdim>(id, coord) {
  dof_ = Tdof;
  force_.resize(Tdof);
  velocity_.resize(Tdof);
  momentum_.resize(Tdof);
  acceleration_.resize(Tdof);
  this->initialise();
}

// Initialise nodal properties
//! \tparam Tdim Dimension
//! \tparam Tdof Degrees of Freedom
//! \tparam Tnphases Number of phases
template <unsigned Tdim, unsigned Tdof, unsigned Tnphases>
void mpm::Node<Tdim, Tdof, Tnphases>::initialise() {
  force_.setZero();
  velocity_.setZero();
  momentum_.setZero();
  acceleration_.setZero();
}

// Assign nodal force
//! \tparam Tdim Dimension
//! \tparam Tdof Degrees of Freedom
//! \tparam Tnphases Number of phases
template <unsigned Tdim, unsigned Tdof, unsigned Tnphases>
void mpm::Node<Tdim, Tdof, Tnphases>::assign_force(const Eigen::VectorXd& force) {
  try {
    if (force.size() != force_.size()) {
      throw std::runtime_error("Nodal force degrees of freedom don't match");
    }
    // Assign force
    force_ = force;
  } catch (std::exception& exception) {
    std::cerr << exception.what() << '\n';
  }
}

// Assign nodal velocity
//! \tparam Tdim Dimension
//! \tparam Tdof Degrees of Freedom
//! \tparam Tnphases Number of phases
template <unsigned Tdim, unsigned Tdof, unsigned Tnphases>
void mpm::Node<Tdim, Tdof, Tnphases>::assign_velocity(const Eigen::VectorXd& velocity) {
  try {
    if (velocity.size() != velocity_.size()) {
      throw std::runtime_error("Nodal velocity degrees of freedom don't match");
    }
    // Assign velocity
    velocity_ = velocity;
  } catch (std::exception& exception) {
    std::cerr << exception.what() << '\n';
  }
}

// Assign nodal momentum
//! \tparam Tdim Dimension
//! \tparam Tdof Degrees of Freedom
//! \tparam Tnphases Number of phases
template <unsigned Tdim, unsigned Tdof, unsigned Tnphases>
void mpm::Node<Tdim, Tdof, Tnphases>::assign_momentum(const Eigen::VectorXd& momentum) {
  try {
    if (momentum.size() != momentum_.size()) {
      throw std::runtime_error("Nodal momentum degrees of freedom don't match");
    }
    // Assign momentum
    momentum_ = momentum;
  } catch (std::exception& exception) {
    std::cerr << exception.what() << '\n';
  }
}

// Assign nodal acceleration
//! \tparam Tdim Dimension
//! \tparam Tdof Degrees of Freedom
//! \tparam Tnphases Number of phases
template <unsigned Tdim, unsigned Tdof, unsigned Tnphases>
void mpm::Node<Tdim, Tdof, Tnphases>::assign_acceleration(const Eigen::VectorXd& acceleration) {
  try {
    if (acceleration.size() != acceleration_.size()) {
      throw std::runtime_error(
          "Nodal acceleration degrees of freedom don't match");
    }
    // Assign acceleration
    acceleration_ = acceleration;
  } catch (std::exception& exception) {
    std::cerr << exception.what() << '\n';
  }
}