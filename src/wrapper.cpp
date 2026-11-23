// wrapper.cpp — part of codex-unlimited.

#include "codexunlimited/wrapper.h"

#include <cstdio>

namespace codexunlimited {

Wrapper::Wrapper(const std::string& config_path)
    : config_path_(config_path) {}

void Wrapper::configure(const std::string& key, const std::string& value) {
    if (key == "verbose") verbose_ = (value == "true");
}

bool Wrapper::run() {
    if (verbose_) std::fprintf(stderr, "[codex-unlimited] wrapper: run\n");
    // core logic lives here
    return true;
}

}  // namespace codexunlimited
