package pl.lukesawicki;

import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.*;

import javax.swing.JPanel;
import javax.swing.Timer;

public class Renderer extends JPanel implements ActionListener {

	private static final long serialVersionUID = 1L;

	public int windowWidth;
	public int windowHeight;

	Timer timer;
	BufferedImage image;
	byte[] pixelsTable;

	public Renderer(int windowWidth, int windowHeight) {
		this.windowWidth = windowWidth;
		this.windowHeight = windowHeight;
		image = new BufferedImage(windowWidth, windowHeight, BufferedImage.TYPE_3BYTE_BGR);
		pixelsTable = ((DataBufferByte) image.getRaster().getDataBuffer()).getData();
		setFocusable(true);
		timer = new Timer(10, this);
		timer.start();
	}

	public void paint(Graphics graphics) {
		for(int j=0; j < 480; j++) {
			for(int i=0; i< 640; i++) {
				pixelsTable[(j*windowWidth + i) * 3 + 2] = (byte)64;
				pixelsTable[(j*windowWidth + i) * 3 + 1] = 0;
				pixelsTable[(j*windowWidth + i) * 3 + 0] = 0;

			}
		}
		super.paint(graphics);
		graphics.drawImage(image, 0, 0, null);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		repaint();
	}

	public void drawLine() {
		
	}
}
