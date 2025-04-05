// New file: chrome/browser/memory/tab_discarding_policy.cc

#include "base/memory/memory_pressure_listener.h"
#include "chrome/browser/ui/tabs/tab_strip_model.h"

namespace {

// Enhanced tab discarding policy that's more aggressive than default
class EnhancedTabDiscardingPolicy {
 public:
  EnhancedTabDiscardingPolicy() {
    memory_pressure_listener_ = std::make_unique<base::MemoryPressureListener>(
        base::BindRepeating(&EnhancedTabDiscardingPolicy::OnMemoryPressure,
                            base::Unretained(this)));
  }

  void OnMemoryPressure(
      base::MemoryPressureListener::MemoryPressureLevel level) {
    if (level == base::MemoryPressureListener::MEMORY_PRESSURE_LEVEL_MODERATE) {
      // Discard tabs that have been inactive for more than 3 minutes
      DiscardTabsInactiveForMinutes(3);
    } else if (level == 
              base::MemoryPressureListener::MEMORY_PRESSURE_LEVEL_CRITICAL) {
      // More aggressive discarding under critical memory pressure
      DiscardTabsInactiveForMinutes(1);
      CleanupRendererCaches();
    }
  }

 private:
  void DiscardTabsInactiveForMinutes(int inactive_minutes) {
    // Implementation to discard tabs inactive for specified minutes
  }

  void CleanupRendererCaches() {
    // Request all renderers to purge memory caches
  }

  std::unique_ptr<base::MemoryPressureListener> memory_pressure_listener_;
};

}  // namespace
