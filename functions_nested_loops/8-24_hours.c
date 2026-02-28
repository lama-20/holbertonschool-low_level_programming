#include "main.h"

/**
 * jack_bauer - Prints every minute of the day
 *
 * Description: Starting from 00:00 to 23:59
 *
 * Return: void
 */
void jack_bauer(void)
{
	int hour, minute;

	for (hour = 0; hour < 24; hour++)
	{
		for (minute = 0; minute < 60; minute++)
		{
			/* طباعة رقم الساعات الأول (العشرات) */
			_putchar((hour / 10) + '0');
			/* طباعة رقم الساعات الثاني (الآحاد) */
			_putchar((hour % 10) + '0');
			/* طباعة النقطتين الفاصلتين */
			_putchar(':');
			/* طباعة رقم الدقائق الأول (العشرات) */
			_putchar((minute / 10) + '0');
			/* طباعة رقم الدقائق الثاني (الآحاد) */
			_putchar((minute % 10) + '0');
			/* طباعة سطر جديد بعد كل دقيقة */
			_putchar('\n');
		}
	}
}
