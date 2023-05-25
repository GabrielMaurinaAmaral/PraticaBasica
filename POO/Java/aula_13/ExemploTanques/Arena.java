package POO.Java.aula_13.ExemploTanques;

import Tanque;
import java.awt.*;
import java.awt.event.*;
import java.util.HashSet;
import javax.swing.*;

public class Arena extends JComponent implements MouseListener, ActionListener {
    private int w, h;
    private HashSet<Tanque> tanques;
    private Timer timer;

    public Arena(int w, int h) {
        this.w = w;
        this.h = h;
        tanques = new HashSet<Tanque>();
        addMouseListener(this);
        // Timer-javax.swing ->dispara um ou mais ActionEvent em intervalo especificado
        // em milisegundos - invocando o actionPerformed da classe
        timer = new Timer(500, this);
        timer.start();
    }

    public void adicionaTanque(Tanque t) {
        tanques.add(t);
    }

    public Dimension getMaximumSize() {
        return getPreferredSize();
    }

    public Dimension getMinimumSize() {
        return getPreferredSize();
    }

    public Dimension getPreferredSize() {
        return new Dimension(w, h);
    }

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2d.setColor(new Color(245, 245, 255));
        g2d.fillRect(0, 0, w, h);
        g2d.setColor(new Color(220, 220, 220));
        for (int w = 0; w <= w; w += 20)
            g2d.drawLine(w, 0, w, h);
        for (int h = 0; h <= h; h += 20)
            g2d.drawLine(0, h, w, h);
        // Desenhamos todos os tanques
        for (Tanque t : tanques)
            t.draw(g2d);
    }

    public void mouseClicked(MouseEvent e)
    {
        for(Tanque t:tanques) t.setEst ́aAtivo(false);
        for(Tanque t:tanques){
            boolean clicado = t.getRectEnvolvente().contains(e.getX(),e.getY());
            
            if (clicado){
                t.setEstaAtivo(true);
                
                switch(e.getButton()){
                    case MouseEvent.BUTTON1: t.giraAntiHor ́ario(3); break;
                    case MouseEvent.BUTTON2: t.aumentaVelocidade(); break;
                    case MouseEvent.BUTTON3: t.giraHor ́ario(3); break;
                }
                break;
            }
        }
        repaint();
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public void mousePressed(MouseEvent e) {
    }

    public void mouseReleased(MouseEvent e) {
    }

    public void actionPerformed(ActionEvent e) {
        for (Tanque t : tanques)
            t.move();
        repaint();
    }
}
