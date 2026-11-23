// main.cpp — entry point. Wires config and subsystems together.

#include "codexunlimited/settings.h"
#include "codexunlimited/wrapper.h"
#include "codexunlimited/rotator.h"
#include "codexunlimited/keychain.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    codexunlimited::Settings settings = codexunlimited::Settings::load_default();
    codexunlimited::Wrapper wrapper(settings.store_path);
    codexunlimited::Rotator rotator(settings.store_path);
    codexunlimited::Keychain keychain(settings.store_path);
    std::fprintf(stderr, "[codex-unlimited] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
