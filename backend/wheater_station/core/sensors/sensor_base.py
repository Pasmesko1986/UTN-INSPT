from core.uart.uart import SerialUART
from typing import Union

class Sensor(SerialUART):
    __VCC__ = 3.3
    __RESOLUTION__ = 4096
    name: str
    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
    
    def counts_to_voltage(self, counts: Union[str, int]):
        voltage = (self.__VCC__/self.__RESOLUTION__)*counts
        return voltage

    def single_read(self):
        value = self.get_counts(target=self.name)
        return value
