// Generated from /home/william/compiler/MyCompiler/source/calculator.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class calculatorLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T_ADD=8, T_SUB=9, 
		T_MUL=10, T_DIV=11, T_MOD=12, T_AND=13, T_FUNC=14, T_RETURN=15, T_ID=16, 
		T_DIGIT=17, WS=18, LineComment=19, MultiLineComment=20;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T_ADD", "T_SUB", 
			"T_MUL", "T_DIV", "T_MOD", "T_AND", "T_FUNC", "T_RETURN", "T_ID", "T_DIGIT", 
			"WS", "LineComment", "MultiLineComment"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "','", "'{'", "'}'", "'='", "';'", "'+'", "'-'", 
			"'*'", "'/'", "'%'", "'&'", "'function'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "T_ADD", "T_SUB", "T_MUL", 
			"T_DIV", "T_MOD", "T_AND", "T_FUNC", "T_RETURN", "T_ID", "T_DIGIT", "WS", 
			"LineComment", "MultiLineComment"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public calculatorLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "calculator.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\u0004\u0000\u0014\u0081\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002"+
		"\u0001\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002"+
		"\u0004\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002"+
		"\u0007\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002"+
		"\u000b\u0007\u000b\u0002\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e"+
		"\u0002\u000f\u0007\u000f\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011"+
		"\u0002\u0012\u0007\u0012\u0002\u0013\u0007\u0013\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0002\u0001\u0002\u0001\u0003\u0001\u0003"+
		"\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006"+
		"\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\n\u0001"+
		"\n\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001"+
		"\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001"+
		"\u000f\u0005\u000fV\b\u000f\n\u000f\f\u000fY\t\u000f\u0001\u0010\u0001"+
		"\u0010\u0005\u0010]\b\u0010\n\u0010\f\u0010`\t\u0010\u0001\u0011\u0004"+
		"\u0011c\b\u0011\u000b\u0011\f\u0011d\u0001\u0011\u0001\u0011\u0001\u0012"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0005\u0012m\b\u0012\n\u0012\f\u0012"+
		"p\t\u0012\u0001\u0012\u0001\u0012\u0001\u0013\u0001\u0013\u0001\u0013"+
		"\u0001\u0013\u0005\u0013x\b\u0013\n\u0013\f\u0013{\t\u0013\u0001\u0013"+
		"\u0001\u0013\u0001\u0013\u0001\u0013\u0001\u0013\u0001y\u0000\u0014\u0001"+
		"\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005\u000b\u0006\r\u0007"+
		"\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0019\r\u001b\u000e\u001d"+
		"\u000f\u001f\u0010!\u0011#\u0012%\u0013\'\u0014\u0001\u0000\u0005\u0002"+
		"\u0000AZaz\u0003\u000009AZaz\u0001\u000009\u0003\u0000\t\n\r\r  \u0002"+
		"\u0000\n\n\r\r\u0085\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001"+
		"\u0000\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001"+
		"\u0000\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000"+
		"\u0000\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000"+
		"\u0000\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000"+
		"\u0000\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000"+
		"\u0000\u0000\u0019\u0001\u0000\u0000\u0000\u0000\u001b\u0001\u0000\u0000"+
		"\u0000\u0000\u001d\u0001\u0000\u0000\u0000\u0000\u001f\u0001\u0000\u0000"+
		"\u0000\u0000!\u0001\u0000\u0000\u0000\u0000#\u0001\u0000\u0000\u0000\u0000"+
		"%\u0001\u0000\u0000\u0000\u0000\'\u0001\u0000\u0000\u0000\u0001)\u0001"+
		"\u0000\u0000\u0000\u0003+\u0001\u0000\u0000\u0000\u0005-\u0001\u0000\u0000"+
		"\u0000\u0007/\u0001\u0000\u0000\u0000\t1\u0001\u0000\u0000\u0000\u000b"+
		"3\u0001\u0000\u0000\u0000\r5\u0001\u0000\u0000\u0000\u000f7\u0001\u0000"+
		"\u0000\u0000\u00119\u0001\u0000\u0000\u0000\u0013;\u0001\u0000\u0000\u0000"+
		"\u0015=\u0001\u0000\u0000\u0000\u0017?\u0001\u0000\u0000\u0000\u0019A"+
		"\u0001\u0000\u0000\u0000\u001bC\u0001\u0000\u0000\u0000\u001dL\u0001\u0000"+
		"\u0000\u0000\u001fS\u0001\u0000\u0000\u0000!Z\u0001\u0000\u0000\u0000"+
		"#b\u0001\u0000\u0000\u0000%h\u0001\u0000\u0000\u0000\'s\u0001\u0000\u0000"+
		"\u0000)*\u0005(\u0000\u0000*\u0002\u0001\u0000\u0000\u0000+,\u0005)\u0000"+
		"\u0000,\u0004\u0001\u0000\u0000\u0000-.\u0005,\u0000\u0000.\u0006\u0001"+
		"\u0000\u0000\u0000/0\u0005{\u0000\u00000\b\u0001\u0000\u0000\u000012\u0005"+
		"}\u0000\u00002\n\u0001\u0000\u0000\u000034\u0005=\u0000\u00004\f\u0001"+
		"\u0000\u0000\u000056\u0005;\u0000\u00006\u000e\u0001\u0000\u0000\u0000"+
		"78\u0005+\u0000\u00008\u0010\u0001\u0000\u0000\u00009:\u0005-\u0000\u0000"+
		":\u0012\u0001\u0000\u0000\u0000;<\u0005*\u0000\u0000<\u0014\u0001\u0000"+
		"\u0000\u0000=>\u0005/\u0000\u0000>\u0016\u0001\u0000\u0000\u0000?@\u0005"+
		"%\u0000\u0000@\u0018\u0001\u0000\u0000\u0000AB\u0005&\u0000\u0000B\u001a"+
		"\u0001\u0000\u0000\u0000CD\u0005f\u0000\u0000DE\u0005u\u0000\u0000EF\u0005"+
		"n\u0000\u0000FG\u0005c\u0000\u0000GH\u0005t\u0000\u0000HI\u0005i\u0000"+
		"\u0000IJ\u0005o\u0000\u0000JK\u0005n\u0000\u0000K\u001c\u0001\u0000\u0000"+
		"\u0000LM\u0005r\u0000\u0000MN\u0005e\u0000\u0000NO\u0005t\u0000\u0000"+
		"OP\u0005u\u0000\u0000PQ\u0005r\u0000\u0000QR\u0005n\u0000\u0000R\u001e"+
		"\u0001\u0000\u0000\u0000SW\u0007\u0000\u0000\u0000TV\u0007\u0001\u0000"+
		"\u0000UT\u0001\u0000\u0000\u0000VY\u0001\u0000\u0000\u0000WU\u0001\u0000"+
		"\u0000\u0000WX\u0001\u0000\u0000\u0000X \u0001\u0000\u0000\u0000YW\u0001"+
		"\u0000\u0000\u0000Z^\u0007\u0002\u0000\u0000[]\u0007\u0002\u0000\u0000"+
		"\\[\u0001\u0000\u0000\u0000]`\u0001\u0000\u0000\u0000^\\\u0001\u0000\u0000"+
		"\u0000^_\u0001\u0000\u0000\u0000_\"\u0001\u0000\u0000\u0000`^\u0001\u0000"+
		"\u0000\u0000ac\u0007\u0003\u0000\u0000ba\u0001\u0000\u0000\u0000cd\u0001"+
		"\u0000\u0000\u0000db\u0001\u0000\u0000\u0000de\u0001\u0000\u0000\u0000"+
		"ef\u0001\u0000\u0000\u0000fg\u0006\u0011\u0000\u0000g$\u0001\u0000\u0000"+
		"\u0000hi\u0005/\u0000\u0000ij\u0005/\u0000\u0000jn\u0001\u0000\u0000\u0000"+
		"km\b\u0004\u0000\u0000lk\u0001\u0000\u0000\u0000mp\u0001\u0000\u0000\u0000"+
		"nl\u0001\u0000\u0000\u0000no\u0001\u0000\u0000\u0000oq\u0001\u0000\u0000"+
		"\u0000pn\u0001\u0000\u0000\u0000qr\u0006\u0012\u0000\u0000r&\u0001\u0000"+
		"\u0000\u0000st\u0005/\u0000\u0000tu\u0005*\u0000\u0000uy\u0001\u0000\u0000"+
		"\u0000vx\t\u0000\u0000\u0000wv\u0001\u0000\u0000\u0000x{\u0001\u0000\u0000"+
		"\u0000yz\u0001\u0000\u0000\u0000yw\u0001\u0000\u0000\u0000z|\u0001\u0000"+
		"\u0000\u0000{y\u0001\u0000\u0000\u0000|}\u0005*\u0000\u0000}~\u0005/\u0000"+
		"\u0000~\u007f\u0001\u0000\u0000\u0000\u007f\u0080\u0006\u0013\u0000\u0000"+
		"\u0080(\u0001\u0000\u0000\u0000\u0006\u0000W^dny\u0001\u0006\u0000\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}