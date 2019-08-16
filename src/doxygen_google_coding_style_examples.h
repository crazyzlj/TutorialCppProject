/*!
 * \file doxygen_google_coding_style_examples.h
 * \brief Examples of coding and documenting styles based on Doxygen and Google Coding Style.
 *        Additional brief introduction should be placed here.
 * 
 * More detailed introduction of this header file could provided here.
 * Although several styles of comment blocks are supported by Doxygen, 
 * the following examples are highly recommended to keep the style consistent.
 * These examples are referenced from:
 * - Doxygen Official Document: http://www.doxygen.nl/manual/docblocks.html
 * - Google C++ Coding Style: https://google.github.io/styleguide/cppguide.html
 * - The actual project CCGL by Liangjun Zhu: https://github.com/crazyzlj/CCGL
 * 
 * The detail introduction block also support bullets, e.g., recording changelogs.
 * I recommended the basic format: "YYYY-MM-DD - <NAME> - <CHANGELOG>".
 * 
 * Changelog:
 *   - 1. 2018-08-12 - lj - Initial implementation.
 *
 * \author Liangjun Zhu (zlj@lreis.ac.cn)
 * \version 1.0
 */
#ifndef DOXYGEN_GOOGLE_CODING_STYLE_EXAMPLES_H
#define DOXYGEN_GOOGLE_CODING_STYLE_EXAMPLES_H

#include <exception>

/********** To document global objects (macros, typedefs, enum, functions, etc), 
 * you must document the file in which they are defined. 
 * In other words, there must at least be a \file **********/

/*! A approximation of PI */
#ifndef PI
#define PI              3.14159265358979323846f
#endif /* PI */

/*! Default NoData value for raster data etc. */
#ifndef NODATA_VALUE
#define NODATA_VALUE    (-9999.0f)
#endif /* NODATA_VALUE */

/*! 4-byte (32-bit) signed integer */
typedef signed __int32 vint32_t;
/*! 4-byte (32-bit) unsigned integer */
typedef unsigned __int32 vuint32_t;
typedef signed __int64 vint64_t;    ///< 8-byte (64-bit) signed integer
typedef unsigned __int64 vuint64_t; ///< 8-byte (64-bit) unsigned integer

/*!
 * \enum LayeringMethod
 * \ingroup base
 * \brief Grid layering method for routing and parallel computing.
 *        Reference: Liu et al., 2014, EM&S, 51, 221-227. https://doi.org/10.1016/j.envsoft.2013.10.005
 */
enum LayeringMethod {
    UP_DOWN, ///< layering-from-source method, default
    DOWN_UP  ///< layering-from-outlet method
};

/*!
 * \brief Check if the IP address is valid.
 * \param[in] ip \a char* IP address.
 * \return true or false
 */
bool IsIpAddress(const char* ip);

/*!
 * \class ModelException
 * \brief Print the exception message
 */
class ModelException: public std::exception {
public:
    /*! Constructor - brief introduction can be defined in the header file. */
    ModelException(const string& class_name, const string& function_name, const string& msg);

    /*!
     * \brief Construct error information (string version)
     * \return string error information
     */
    string ToString();

    /*!
     * \brief Overload function to construct error information
     * \return char* error information
     */
    const char* what() const NOEXCEPT OVERRIDE;

private:
    std::runtime_error runtime_error_; ///< runtime error
};


#endif /* DOXYGEN_GOOGLE_CODING_STYLE_EXAMPLES_H */
