/** @file DoxyExample.h
 *  @brief Example header file for Doxygen comments.
 *
 *  This is an example header file demonstrating Doxygen
 *  comments for various function prototypes.
 */

/** @mainpage Example Project
 *
 *  @section intro_sec Introduction
 *
 *  This is an example project to demonstrate Doxygen comments
 *  in C source files and header files. The example contains
 *  functions for initializing the system, setting and getting
 *  system mode, and performing addition.
 *
 *  @section functions_sec Functions
 *
 *  This project consists of the following functions:
 *  - init_system()
 *  - set_system_mode()
 *  - get_system_mode()
 *  - add()
 */

#ifndef DOXY_EXAMPLE_H
#define DOXY_EXAMPLE_H

/** @defgroup example_group Example Group
 *  @{
 */

/** @brief Initialize the system.
 *
 *  This function initializes the system without any arguments.
 */
void init_system(void);

/** @brief Set the system mode.
 *
 *  @param mode The desired mode for the system.
 */
void set_system_mode(int mode);

/** @brief Get the system mode.
 *
 *  This function returns the current system mode without any arguments.
 *
 *  @return The current system mode.
 */
int get_system_mode(void);

/** @brief Calculate the sum of two integers.
 *
 *  @param a The first integer.
 *  @param b The second integer.
 *  @return The sum of the two input integers.
 */
int add(int a, int b);

/** @} */ // end of example_group

#endif /* DOXY_EXAMPLE_H */