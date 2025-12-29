#include "Project.h"

#include <cstdint>
#include <fstream>
#include <iostream>

namespace {
const char MAGIC_ID[] = "PROJ";
const int32_t CURRENT_FORMAT_VERSION = 1;

// Helper to write string in length-prefixed format
void WriteString(std::ofstream& out, const std::string& str) {
  uint32_t length = static_cast<uint32_t>(str.length());
  out.write(reinterpret_cast<const char*>(&length), sizeof(length));
  if (length > 0) {
    out.write(str.c_str(), length);
  }
}

// Helper to read length-prefixed string
bool ReadString(std::ifstream& in, std::string& str) {
  uint32_t length = 0;
  in.read(reinterpret_cast<char*>(&length), sizeof(length));
  if (in.fail()) return false;

  if (length > 0) {
    str.resize(length);
    in.read(&str[0], length);
    if (in.fail()) return false;
  } else {
    str.clear();
  }
  return true;
}
}  // namespace

Project::Project() {}

Project::~Project() {}

std::string Project::GetName() const { return name_; }

std::string Project::GetVersion() const { return version_; }

void Project::SetName(const std::string& name) { name_ = name; }

void Project::SetVersion(const std::string& version) { version_ = version; }

bool Project::Save(const std::string& filename) const {
  std::ofstream out(filename, std::ios::binary);
  if (!out.is_open()) {
    return false;
  }

  // 1. Write Header
  out.write(MAGIC_ID, sizeof(MAGIC_ID) - 1);  // Don't write null terminator for magic

  // 2. Write Format Version
  out.write(reinterpret_cast<const char*>(&CURRENT_FORMAT_VERSION), sizeof(CURRENT_FORMAT_VERSION));

  // 3. Write Data
  WriteString(out, name_);
  WriteString(out, version_);

  return out.good();
}

bool Project::Load(const std::string& filename) {
  std::ifstream in(filename, std::ios::binary);
  if (!in.is_open()) {
    return false;
  }

  // 1. Check Header
  char magic[4];
  in.read(magic, 4);
  if (in.fail() || std::string(magic, 4) != std::string(MAGIC_ID, 4)) {
    return false;
  }

  // 2. Check Version
  int32_t formatVersion = 0;
  in.read(reinterpret_cast<char*>(&formatVersion), sizeof(formatVersion));
  if (in.fail()) return false;

  // (Could handle older versions here in the future)

  // 3. Read Data
  if (!ReadString(in, name_)) return false;
  if (!ReadString(in, version_)) return false;

  return true;
}
