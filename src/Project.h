#pragma once
#include <string>

class Project {
 public:
  Project();
  virtual ~Project();

  // Getters
  std::string GetName() const;
  std::string GetVersion() const;

  // Setters
  void SetName(const std::string& name);
  void SetVersion(const std::string& version);

  // I/O
  bool Save(const std::string& filename) const;
  bool Load(const std::string& filename);

 private:
  std::string name_;
  std::string version_;
};
