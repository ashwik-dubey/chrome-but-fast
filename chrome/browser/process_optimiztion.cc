namespace {

// Configure more aggressive process model settings
void ConfigureOptimizedProcessModel() {
  // Increase the limit for renderer reuse
  content::RenderProcessHost::SetMaxRendererProcessCount(4);  // Lower than default

  // Enable process sharing for related sites
  content::SiteInstance::SetMaxProcessesPerSiteForTesting(1);

  // Enable more aggressive memory reclamation for background renderers
  // This purges JavaScript heap memory more frequently
  content::RenderProcessHostImpl::SetMemoryPurgeDelayForTesting(
      base::Minutes(2));
}

// Implements more aggressive background tab throttling
void EnableAggressiveBackgroundTabThrottling() {
  // Reduce CPU budget for background tabs
  SetBackgroundTimerThrottling(true);
  SetBackgroundCPUThrottlingRate(0.1);  // More aggressive than default
  
  // Freeze JavaScript timers after longer inactivity
  SetJavaScriptTimerDelayAfterInactivity(base::Minutes(1));  // More aggressive
}

}
