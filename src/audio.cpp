#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>
#include <audio.h>

/* Carrega a engine de áudio */
ma_engine engine;
/* Armazena todos os áudios */
ma_sound *audios;

void loadAudio(ma_sound *sound, const char *filename)
{
    if (ma_sound_init_from_file(&engine, filename, 0, NULL, NULL, sound) != MA_SUCCESS)
    {
        fprintf(stderr, "Falha ao carregar o som %s.\n", filename);
        exit(EXIT_FAILURE);
    }
}

// Inicializa os áudios
void initAudios()
{
    // Inicia a engine de áudio e verifica se teve sucesso
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS)
    {
        fprintf(stderr, "Falha ao inicializar o motor de audio.\n");
        exit(EXIT_FAILURE);
    }
    // Aloca espaço para todos os áudios
    audios = (ma_sound *)malloc(sizeof(ma_sound) * NUM_AUDIOS);
    if (!audios)
    {
        fprintf(stderr, "Erro ao inicializar os audios\n");
        exit(EXIT_FAILURE);
    }

    // Carrega todos os áudios usados no Jogo
    loadAudio(&audios[SHOT], "../assets/shot.mp3");
}

void freeAudios()
{
    for(int i = 0; i < NUM_AUDIOS; i++) {
        ma_sound_uninit(&audios[i]); // Libera cada áudio da memória
    }
    ma_engine_uninit(&engine); // Libera a engine de áudio
}

// Toca o som
void playSound(int audioID)
{
    ma_sound_start(&audios[audioID]);
}
