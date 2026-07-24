#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <time.h>

// Returns current time in microseconds directly from the OS
static PyObject* method_get_time_us(PyObject* self, PyObject* args) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    
    unsigned long long microseconds = (unsigned long long)ts.tv_sec * 1000000 + (ts.tv_nsec / 1000);
    return PyLong_FromUnsignedLongLong(microseconds);
}

// Register C methods to Python
static PyMethodDef BenchpyMethods[] = {
    {"get_time_us", method_get_time_us, METH_NOARGS, "Get high-precision timestamp in microseconds."},
    {NULL, NULL, 0, NULL}
};

// Define module
static struct PyModuleDef benchpymodule = {
    PyModuleDef_HEAD_INIT,
    "benchpy_core",
    "C extension for low-overhead performance benchmarking.",
    -1,
    BenchpyMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_benchpy_core(void) {
    return PyModule_Create(&benchpymodule);
}
