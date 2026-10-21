import matplotlib.pyplot as plt 
import matplotlib.patches as patches 

def construir_plano_cartesiano(eixo_x:float,eixo_y:float, title:str):
    fig, ax = plt.subplots(figsize = (7,7))
    
    fig.patch.set_facecolor('black')
    ax.set_facecolor('black')
    ax.set_title("Dispositivo lógico: Clique 3 vezes", color='white', fontsize=14)
    
    ax.grid(True, color = 'white', linestyle = '--', alpha=0.3)
    ax.tick_params(colors = 'white')
    
    for spine in ax.spines.values():
        spine.set_color('white')
    
    ax.set_xlim(0,eixo_x)
    ax.set_ylim(0,eixo_y)
    ax.set_title(title)
    ax.grid(True, linestyle='--', alpha = 0.5)
    ax.set_xlabel("Eixo X")
    ax.set_ylabel("Eixo Y")
    
    return fig, ax
    
def main():
    print("Dispositivos de entrada...")
    
    fig, ax = construir_plano_cartesiano(eixo_x=100,eixo_y=100, title="Clique 3 vezes para gerar a Primitiva Gráfica")
    
    cordenadas_entrada = []
    
    def ao_clicar(event):    
        if event.xdata is None or event.ydata is None:
            return

        x,y = event.xdata, event.ydata
        cordenadas_entrada.append([x,y])
        print(f"Entrada do mouse --> Coordenadas: ({x:.2f}, {y:.2f})")
        ax.plot(x,y,'ro')
        fig.canvas.draw()
        
        if len(cordenadas_entrada) == 3:
            print("Desenhando a primitiva de Poligono")
            triangulo = patches.Polygon(
                cordenadas_entrada,closed=True,
                fill=True, color='green',
                alpha=0.6,edgecolor='red',linewidth=3)
            ax.add_patch(triangulo)
            fig.canvas.draw()
            cordenadas_entrada.clear()

    fig.canvas.mpl_connect('button_press_event',ao_clicar)
    
    print("Aguardando entrada do usuário na interface gráfica...")
    
    plt.show()
    
if __name__ == "__main__":
    main()
        
    

    