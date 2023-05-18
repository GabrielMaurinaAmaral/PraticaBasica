
public class Aula_7_Revista {
    private String titulo;
    private int quant_page, num_edicao, mes, ano;

    public Aula_7_Revista() {
        this.titulo = "";
        this.quant_page = 0;
        this.num_edicao = 0;
        this.mes = 0;
        this.ano = 0;
    }

    public Aula_7_Revista(String titulo, int quant_page, int num_edicao, int mes, int ano) {
        this.titulo = titulo;
        this.quant_page = quant_page;
        this.num_edicao = num_edicao;
        this.mes = mes;
        this.ano = ano;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String toString() {
        return "titulo: " + titulo +
                "\nquantidade de page: " + quant_page +
                "\nnumero da edicao: " + num_edicao +
                "\ndata de lancamento:" + mes + "/" + ano;
    }
}
