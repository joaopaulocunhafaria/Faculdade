package Lab4;

public class Lampada {


	private String modelo;
	private int estado;
	private float tensao;
	static int cont;
	
	
	
	
	public Lampada(String modelo, float tensao) {
		super();
		this.modelo = modelo;
		this.tensao = tensao;
		cont++;
	}
	
	
	public void acender() {
		this.estado=1;
		
	}
	public void apagar() {
		this.estado=0;
	}
	
	
	public void estado() {
		if(this.estado==0) {
			System.out.println(" A lampada esta apagada!");
		}else {
			System.out.println(" A lampada esta acessa!");
		}
		
	}


	public String getModelo() {
		return modelo;
	}


	public void setModelo(String modelo) {
		this.modelo = modelo;
	}


	public int getEstado() {
		return estado;
	}


	public void setEstado(int estado) {
		this.estado = estado;
	}


	public float getTensao() {
		return tensao;
	}


	public void setTensao(float tensao) {
		this.tensao = tensao;
	}
}
