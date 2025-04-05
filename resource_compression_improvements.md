# Resource Compression Improvements

1. Use Brotli compression for all resources:
   - Add `compress="brotli"` attribute to HTML, JS, CSS files in .grd files
   - Configure optimal Brotli compression level (trade-off between size and decompression speed)

2. Reduce image sizes:
   - Convert PNG images to WebP where possible
   - Use vector images (SVG) instead of raster where appropriate
   - Implement lazy loading for images

3. L10n String Optimization:
   - Compress localization files with gzip/brotli
   - Only load strings for the current locale
