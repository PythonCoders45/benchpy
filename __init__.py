import benchpy_core
import tracemalloc

def profile(func, *args, **kwargs):
    tracemalloc.start()
    
    # Calls your custom C code!
    start_us = benchpy_core.get_time_us()
    
    result = func(*args, **kwargs)
    
    end_us = benchpy_core.get_time_us()
    
    _, peak_bytes = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    elapsed_us = end_us - start_us

    return {
        "result": result,
        "time_ms": elapsed_us / 1000.0,
        "time_us": elapsed_us,
        "peak_ram_mb": peak_bytes / (1024 * 1024)
    }
