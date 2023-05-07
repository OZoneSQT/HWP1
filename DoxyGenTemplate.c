/******************************************************************
 * @Title : Digital Input / Output (DIO)
 * @Filename : dio.c
 * @brief This file contains the public interface for My Module.
 * @Author : Jacob W. Beningo
 * @Origin Date : 09/01/2015
 * @Version : 1.0.0
 * @Compiler : TBD
 * @Target : TBD
 * @Notes : None
 *
 * THIS SOFTWARE IS PROVIDED BY BENINGO EMBEDDED GROUP 
 * "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BENINGO 
 * EMBEDDED GROUP OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF 
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * https://www.doxygen.nl/manual/docblocks.html
 * 
 ******************************************************************/

/**
 * @defgroup MyModule My Module
 * @brief This module provides functionality for My Module.
 * @{
 */

/**
 * @brief This enumeration represents possible error codes.
 */
typedef enum {
    MY_MODULE_OK,         /**< The operation completed successfully. */
    MY_MODULE_ERROR,      /**< An unspecified error occurred. */
    MY_MODULE_INVALID_ARG /**< An argument passed to the function was invalid. */
} MyModuleStatus;

/**
 * @brief This structure represents a point in 2D space.
 */
typedef struct {
    int x; /**< The x-coordinate of the point. */
    int y; /**< The y-coordinate of the point. */
} MyModulePoint;

/**
 * @brief This function adds two integers.
 *
 * @param[in] a The first integer to add.
 * @param[in] b The second integer to add.
 *
 * @return The sum of the two integers.
 */
int MyModule_Add(int a, int b);

/**
 * @brief This function calculates the distance between two points.
 *
 * @param[in] p1 The first point.
 * @param[in] p2 The second point.
 *
 * @return The distance between the two points.
 */
float MyModule_Distance(const MyModulePoint* p1, const MyModulePoint* p2);

/** @} */ /* end of MyModule group */
