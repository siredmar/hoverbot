/******************************************************************************
 * @file    brushless_hall_sensor.h
 * @author  Rémi Pincent - INRIA
 * @date    24/11/2016
 *
 * @brief Get sensor speed in deg/s from some hall sensors
 *
 * Project : hoverbot
 * Contact:  Rémi Pincent - remi.pincent@inria.fr
 *
 * Revision History:
 * https://github.com/OpHaCo/hoverbot.git 
 * 
 * LICENSE :
 * hoverbot (c) by Rémi Pincent
 * hoverbot is licensed under a
 * Creative Commons Attribution-NonCommercial 3.0 Unported License.
 *
 * You should have received a copy of the license along with this
 * work.  If not, see <http://creativecommons.org/licenses/by-nc/3.0/>.
 *****************************************************************************/
#ifndef BRUSHLESS_HALL_SENSOR
#define BRUSHLESS_HALL_SENSOR
 
/**************************************************************************
 * Include Files
 **************************************************************************/
#include <stdint.h>
#include <IntervalTimer.h>
/**************************************************************************
 * Manifest Constants
 **************************************************************************/

/**************************************************************************
 * Type Definitions
 **************************************************************************/

/**************************************************************************
 * Global variables
 **************************************************************************/

/**************************************************************************
 * Macros
 **************************************************************************/

/**************************************************************************
 * Global Functions Declarations
 **************************************************************************/
class BrushlessHallSensor
{
  public :
    typedef enum{
      SENSOR_1,
      SENSOR_2,
      SENSOR_3,
      OUT_OF_ENUM_SENSOR
    }EHallSensor;
  private :
    volatile int32_t _s32_hallTicks, _s32_periodHallTicks, _s32_lastPeriodHallTicks;
    volatile EHallSensor _e_lastHallSensed;
    uint8_t _u8_hall1Pin, _u8_hall2Pin, _u8_hall3Pin;
    static BrushlessHallSensor* _instance;
    /** Number of ticks for a 2pi rotation */
    static const float NB_TICKS_ROTA;
    
    /** Timer used to capture speed */
    IntervalTimer _captureTimer;
    /** Timer capture period */
    static const uint16_t TIMER_PERIOD_MS;
	public :
    BrushlessHallSensor(uint8_t arg_u8_hall1Pin, uint8_t arg_u8_hall2Pin, uint8_t arg_u8_hall3Pin);
      
    void startSensing(void);
    void stopSensing(void);
    /**
     * Get speed in rad/s 
     */
    float getSpeed(void); 
    inline int32_t getTicks(void){return _s32_hallTicks;}
      
  private :
    static void hall1It(void);
    static void hall2It(void);
    static void hall3It(void);
    static void timerIt(void);
};

#endif /* BRUSHLESS_HALL_SENSOR */
