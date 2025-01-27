import numpy as np
import librosa
from scipy.signal import find_peaks

# Notaların frekansları (Hz)
note_frequencies = {
    "NOTE_B0": 31, "NOTE_C1": 33, "NOTE_CS1": 35, "NOTE_D1": 37,
    "NOTE_DS1": 39, "NOTE_E1": 41, "NOTE_F1": 44, "NOTE_FS1": 46,
    "NOTE_G1": 49, "NOTE_GS1": 52, "NOTE_A1": 55, "NOTE_AS1": 58,
    "NOTE_B1": 62, "NOTE_C2": 65, "NOTE_CS2": 69, "NOTE_D2": 73,
    "NOTE_DS2": 78, "NOTE_E2": 82, "NOTE_F2": 87, "NOTE_FS2": 93,
    "NOTE_G2": 98, "NOTE_GS2": 104, "NOTE_A2": 110, "NOTE_AS2": 117,
    "NOTE_B2": 123, "NOTE_C3": 131, "NOTE_CS3": 139, "NOTE_D3": 147,
    "NOTE_DS3": 156, "NOTE_E3": 165, "NOTE_F3": 175, "NOTE_FS3": 185,
    "NOTE_G3": 196, "NOTE_GS3": 208, "NOTE_A3": 220, "NOTE_AS3": 233,
    "NOTE_B3": 247, "NOTE_C4": 262, "NOTE_CS4": 277, "NOTE_D4": 294,
    "NOTE_DS4": 311, "NOTE_E4": 330, "NOTE_F4": 349, "NOTE_FS4": 370,
    "NOTE_G4": 392, "NOTE_GS4": 415, "NOTE_A4": 440, "NOTE_AS4": 466,
    "NOTE_B4": 494, "NOTE_C5": 523, "NOTE_CS5": 554, "NOTE_D5": 587,
    "NOTE_DS5": 622, "NOTE_E5": 659, "NOTE_F5": 698, "NOTE_FS5": 740,
    "NOTE_G5": 784, "NOTE_GS5": 831, "NOTE_A5": 880, "NOTE_AS5": 932,
    "NOTE_B5": 988, "NOTE_C6": 1047, "NOTE_CS6": 1109, "NOTE_D6": 1175,
    "NOTE_DS6": 1245, "NOTE_E6": 1319, "NOTE_F6": 1397, "NOTE_FS6": 1480,
    "NOTE_G6": 1568, "NOTE_GS6": 1661, "NOTE_A6": 1760, "NOTE_AS6": 1865,
    "NOTE_B6": 1976, "NOTE_C7": 2093, "NOTE_CS7": 2217, "NOTE_D7": 2349,
    "NOTE_DS7": 2489, "NOTE_E7": 2637, "NOTE_F7": 2794, "NOTE_FS7": 2960,
    "NOTE_G7": 3136, "NOTE_GS7": 3322, "NOTE_A7": 3520, "NOTE_AS7": 3729,
    "NOTE_B7": 3951, "NOTE_C8": 4186, "NOTE_CS8": 4435, "NOTE_D8": 4699,
    "NOTE_DS8": 4978
}


# Ses dosyasını yükleme
def process_audio(file_path):
    y, sr = librosa.load(file_path, sr=None)  # Ses dosyasını yükle
    hop_length = 512  # Zaman çözünürlüğü için adım boyu
    D = np.abs(librosa.stft(y))  # Spektrogram
    
    # FFT frekanslarını belirle
    frequencies = librosa.fft_frequencies(sr=sr)
    times = librosa.frames_to_time(range(D.shape[1]), sr=sr, hop_length=hop_length)

    # En baskın frekansları belirle
    peak_indices = [np.argmax(frame) for frame in D.T]
    dominant_frequencies = frequencies[peak_indices]

    # Frekansları notalara eşleştir
    detected_notes = []
    detected_durations = []
    for i, freq in enumerate(dominant_frequencies):
        closest_note = min(note_frequencies, key=lambda note: abs(note_frequencies[note] - freq))
        detected_notes.append(closest_note)
        
        # Çalma süresini hesapla
        if i > 0:
            duration = times[i] - times[i - 1]
            detected_durations.append(np.floor(duration * 1000))
        else:
            detected_durations.append(0)  # İlk nota için süre hesaplanmaz

    return detected_notes, detected_durations

# Ses kaydını işleyelim
file_path = "./mia_tatlises.mp3"  # Analiz edilecek ses dosyası
notes, durations = process_audio(file_path)

# Sonuçları yazdır
print("Detected Notes:", notes)
print("Detected Durations (s):", durations)
print(len(notes))
