# 42_minitalk
<img width="3000" height="2000" alt="image" src="https://github.com/user-attachments/assets/5073b5a8-cc99-45dc-bf1f-a3c533aefc22" />

Minitalk, **Unix sinyallerini kullanarak iki program arasında basit mesajlaşma** sağlayan bir C projesidir.  
Bu proje 42 okulları için geliştirilmiştir ve sinyallerle veri iletimi mantığını anlamanıza yardımcı olur.

---

## Özellikler

- Mesaj gönderen (client) ve mesaj alan (server) programları.
- Her karakter tek tek sinyallerle gönderilir.
- `SIGUSR1` ve `SIGUSR2` sinyalleri kullanılır.
- Çoklu karakter ve kelime desteği.
- Hatalara karşı basit kontrol mekanizması.

---

## Kurulum

1. Repo’yu klonlayın:

```bash
git clone https://github.com/kullanici_adiniz/minitalk.git
cd minitalk
>> make (projeyi derleyin) 
>> ./server (PID öğrenin)
>> ./client $PID "deneme"
