# Alarme

O código foi desenvolvido com o objetivo de permitir o desligamento ou ativação de equipamentos elétricos em momentos específicos do dia.

O script estabelece a conexão do ESP8266 a uma rede Wi-Fi e obtém o horário atual por meio da internet. Com base nesse horário, o script
aciona ou não o módulo rele.

Devido à forma como o horário é obtido, o sistema apresenta as seguintes características:

1. Não perde a configuração em caso de quedas de energia, mesmo sem depender de uma bateria.
2. Requer acesso a uma rede Wi-Fi.
