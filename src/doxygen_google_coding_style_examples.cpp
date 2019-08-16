/*!
 * \file doxygen_google_coding_style_examples.cpp
 * \brief Doxygen code document examples commonly used in the implementation code.
 * 
 * Changelog:
 *   - 1. 2018-08-12 - lj - Initial implementation.
 * 
 * \author Liangjun Zhu (zlj@lreis.ac.cn)
 * \version 1.0
 */
#include "doxygen_google_coding_style_examples.h"

#include <string>

bool IsIpAddress(const char* ip) {
    bool rv = true;
    int tmp1, tmp2, tmp3, tmp4;
    while (true) {
        int i = sscanf(ip, "%d.%d.%d.%d", &tmp1, &tmp2, &tmp3, &tmp4);
        if (i != 4) {
            rv = false;
            break;
        }
        if (tmp1 > 255 || tmp2 > 255 || tmp3 > 255 || tmp4 > 255 ||
            tmp1 < 0 || tmp2 < 0 || tmp3 < 0 || tmp4 < 0) {
            rv = false;
            break;
        }
        for (const char* p_char = ip; *p_char != 0; p_char++) {
            if (*p_char != '.' && (*p_char < '0' || *p_char > '9')) {
                rv = false;
                break;
            }
        }
        break;
    }
    return rv;
}

/*!  Write the detail introduction in the source file to keep the header file compact, and 
 *     allow the implementer of the members more direct access to the documentation.
 * 
 * \param[in] class_name Class name
 * \param[in] function_name Function name
 * \param[in] msg Error message
 */
ModelException::ModelException(const string& class_name, const string& function_name, const string& msg):
    runtime_error_("Class:" + class_name + "\n" + "Function:" + function_name + "\n" + "Message:" + msg) {
}

string ModelException::ToString() {
    return runtime_error_.what();
}

const char* ModelException::what() const NOEXCEPT {
    return runtime_error_.what();
}